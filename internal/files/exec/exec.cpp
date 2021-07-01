#include <list>
#include <vector>
#include <string>
#include <stdio.h>
#include <fstream>
#include <iostream>
#include <charconv>
#include <ncurses.h>
#include "exec.hpp"
#include "./../../bufs/bufs.hpp"

// bool FileHelper::exist_in_buf(int y)
// {
//     for (int i = 0; i < buf.size(); i++)
//     {
//         if (buf[i].y <= y)
//         {
//             return true;
//         }
//     }
//     return false;
// };

void ExecFile::open(char n[])
{
    this->file_name = n;
    this->file = fopen(n, "r+");
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
        _DEFAULT__BUF.add_C(res[i], 0, 0);
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
        //modified = true;
        auto const insert_buf = _INSERT__BUF.get();
        if (!insert_buf.empty())
        {
            for (int i = 0; i < insert_buf.size(); i++)
            {
                fprintf(file, "%c", insert_buf[i]->symbol);
            };
            fprintf(file, "%s", "\n");
        }
    }
};

void ExecFile::auto_save()
{
    auto const default_buf = _DEFAULT__BUF.get();
    if (_is_insert_buf_equal_to_default() || !_INSERT__BUF.is_modified())
    {
        for (int i = 0; i < default_buf.size(); i++)
        {
            fprintf(file, "%c", default_buf[i]->symbol);
        };
    }
};

void ExecFile::close()
{
    if (file != NULL)
    {
        fclose(file);
    }
};

ExecFile _EXEC_FILE;