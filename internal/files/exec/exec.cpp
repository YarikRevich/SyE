#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <fstream>
#include <charconv>
#include <ncurses.h>
#include <stdio.h>
#include "exec.hpp"
#include "./../log/log.hpp"

// bool FileHelper::is_buf_equal_to_default()
// {
//     if ((!buf.empty() && !default_buf.empty()) && (buf.size() == default_buf.size()))
//     {
//         for (int i = 0; i < default_buf.size() - 1; i++)
//         {
//             if (buf[i].symbol != default_buf[i])
//             {
//                 return false;
//             }
//         }
//         return true;
//     }
//     return false;
// };

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

void FileBase::open(char n[])
{
    this->file_name = n;
    this->file = fopen(n, "r+");
};

void FileBuffer::erase(int y, int x)
{
    // _DEV_LOG.write_to_file_str({"SIZE IS", std::to_string(buf.size()), "\n"});
    if (this->buf.size() > 1)
    {
        for (int i = 0; i < this->buf.size(); i++)
        {
            // _DEV_LOG.write_to_file_str({std::to_string(this->buf[i].x), " X IS ", "\n"});
            if (this->buf[i].x == x && this->buf[i].y == y)
            {

                this->buf.erase(this->buf.begin() + i);
            }
        }
    }
    else if (this->buf.size() != 0)
    {
        this->buf.erase(buf.begin());
    }
    // _DEV_LOG.write_to_file_str({"SIZE IS", std::to_string(buf.size()), "\n"});
}

void FileBuffer::add(int s, int y, int x)
{
    for (int i = 0; i < this->buf.size(); i++)
    {
        if (this->buf[i].x == x && this->buf[i].y == y)
        {
            this->erase(y, x);
        }
    }
    this->buf.push_back({s, y, x});
}

std::vector<buf_cell> FileBuffer::get()
{
    return this->buf;
};

std::string FileBase::read()
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
        default_buf.push_back(res[i]);
    }

    fclose(file);

    std::ofstream q(file_name, std::ofstream::out | std::ofstream::trunc);
    q.close();

    file = fopen(file_name.c_str(), "r+");
    return res;
}

void FileBase::save()
{
    if (file != NULL)
    {
        modified = true;
        if (!buf.empty())
        {
            for (int i = 0; i < buf.size(); i++)
            {
                fprintf(file, "%c", buf[i].symbol);
            };
            fprintf(file, "%s", "\n");
        }
    }
};

void FileBase::close()
{
    if (file != NULL)
    {
        fclose(file);
    }
};

void FileBase::auto_save()
{
    if (is_buf_equal_to_default() || !modified)
    {
        for (int i = 0; i < default_buf.size(); i++)
        {
            fprintf(file, "%c", default_buf[i]);
        };
    }
};

FileBase _FILE;