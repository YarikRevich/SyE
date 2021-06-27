#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <fstream>
#include <charconv>
#include <ncurses.h>
#include <stdio.h>
#include "file.hpp"
#include "../log/dev/dev.hpp"

void File::prepare_file(char n[])
{
    file_name = n;
    file = fopen(n, "r+");
};

void File::delete_from_buffer(int y, int x)
{
    if (buf.size() > 1)
    {
        for (int i = 0; i < buf.size(); i++)
        {
            if (buf[i].x == x && buf[i].y == y)
            {
                buf.erase(buf.begin() + i);
            }
        }
    }
    else if (buf.size() != 0)
    {
        buf.erase(buf.begin());
    }
}

void File::save_to_buffer(int s, int y, int x)
{
    buf.push_back({s, y, x});
}

std::vector<buf_cell> File::get_buf()
{
    return buf;
};

std::string File::read_from_file()
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
        default_to_save.push_back(res[i]);
    }

    fclose(file);

    std::ofstream q(file_name, std::ofstream::out | std::ofstream::trunc);
    q.close();

    file = fopen(file_name.c_str(), "r+");
    return res;
}

void File::write_to_file()
{
    if (file != NULL)
    {
        modified = true;
        if (!buf.empty())
        {
            for (int i = 0; i < buf.size(); i++)
            {
                _DEV_LOG.write_to_file_str(std::to_string(buf[i].symbol) + "\n");
                fprintf(file, "%c", buf[i].symbol);
            };
            fprintf(file, "%s", "\n");
        }
    }
};

void File::close_file()
{
    if (file != NULL)
    {
        fclose(file);
    }
};

bool File::is_buf_equal_to_default()
{
    if ((!buf.empty() && !default_to_save.empty()) && (buf.size() == default_to_save.size()))
    {
        for (int i = 0; i < default_to_save.size() - 1; i++)
        {
            if (buf[i].symbol != default_to_save[i])
            {
                return false;
            }
        }
        return true;
    }
    return false;
};

void File::save_default()
{
    if (is_buf_equal_to_default() || !modified)
    {
        for (int i = 0; i < default_to_save.size(); i++)
        {
            fprintf(file, "%c", default_to_save[i]);
        };
    }
};

File _FILE;