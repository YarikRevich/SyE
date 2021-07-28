#include <list>
#include <vector>
#include <string>
#include <stdio.h>
#include <fstream>
#include <iostream>
#include <charconv>
#include <ncurses.h>
#include "exec.hpp"
#include "./../log/log.hpp"
#include "./../../bufs/bufs.hpp"

void ExecFile::open(void *n)
{
    this->file_name = (char *)n;
    this->file = fopen((char *)n, "r+");
};

std::string ExecFile::read()
{
    std::string res;
    if (file != NULL)
    {
        fseek(file, 0, SEEK_END);
        size_t size = ftell(file);
        res.resize(size);
        rewind(file);
        fread(&res[0], 1, size, file);
    };

    for (int i = 0; i < res.size(); i++)
    {
        if (!res.size())
        {
            break;
        }
        _DEFAULT__BUF->addCell(res[i]);
    }

    fclose(file);

    std::ofstream q(file_name, std::ofstream::out | std::ofstream::trunc);
    q.close();

    file = fopen(file_name.c_str(), "r+");
    return res;
}

void ExecFile::save()
{
    if (file != NULL)
    {
        _INSERT__BUF->setModified(true);
        _INSERT__BUF->addEolIfNotExists();
        auto const insert_buf = _INSERT__BUF->getBufferIterator();
        if (!insert_buf.empty())
        {
            for (auto i : std::string("INSERT BUFFER"))
            {
                _LOG__BUF->addCellWithSymbolType(i, CHAR);
            };
            _LOG__BUF->addCellWithSymbolType(10, CHAR);
            for (int i = 0; i < insert_buf.size(); i++)
            {

                _LOG__BUF->addCellWithSymbolType(insert_buf[i]->symbol, CHAR);
                _LOG__BUF->addCellWithSymbolType(' ', CHAR);
                _LOG__BUF->addCellWithSymbolType(insert_buf[i]->symbol, INT);
                _LOG__BUF->addCellWithSymbolType(10, CHAR);
                fprintf(file, "%c", insert_buf[i]->symbol);
            };
        }
    }
};

void ExecFile::auto_save()
{
    // _INSERT__BUF->addEolIfNotExists();

    auto const default_buf = _DEFAULT__BUF->getBufferIterator();
    // auto const insert_buf = _INSERT__BUF->getBufferIterator();

    // _LOG__BUF->addCellWithSymbolType(10, CHAR);
    // for (auto i : std::string("DEFAULT BUFFER"))
    // {
    //     _LOG__BUF->addCellWithSymbolType(i, CHAR);
    // }
    // for (int i = 0; i < default_buf.size(); i++)
    // {
    //     _LOG__BUF->addCellWithSymbolType(10, CHAR);
    //     _LOG__BUF->addCellWithSymbolType(default_buf[i]->symbol, INT);
    // };
    // _LOG__BUF->addCellWithSymbolType(10, CHAR);
    // for (auto i : std::string("INSERT BUFFER"))
    // {
    //     _LOG__BUF->addCellWithSymbolType(i, CHAR);
    // }
    // for (int i = 0; i < insert_buf.size(); i++)
    // {
    //     _LOG__BUF->addCellWithSymbolType(10, CHAR);
    //     _LOG__BUF->addCellWithSymbolType(insert_buf[i]->symbol, INT);
    // };
    // _LOG__BUF->addCellWithSymbolType(10, CHAR);
    // _LOG__BUF->addCellWithSymbolType(isInsertSameToDefaultBuf(), INT);

    // _LOG_FILE->save();
    if (isInsertSameToDefaultBuf() || !_INSERT__BUF->isModified())
    {
        for (int i = 0; i < default_buf.size(); i++)
        {
            fprintf(file, "%c", default_buf[i]->symbol);
        };
    };
};

void ExecFile::close()
{
    if (file != NULL)
    {
        fclose(file);
    }
};

std::string ExecFile::getFileName()
{
    return this->file_name;
};

ExecFile *_EXEC_FILE = new ExecFile;