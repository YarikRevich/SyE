#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <fstream>
#include <charconv>
#include <ncurses.h>
#include <stdio.h>
#include "files.hpp"
#include "./../context/context.hpp"

void File::prepare_file(char n[])
{
    file_name = n;
    file = fopen(n, "r+");
};

void File::delete_from_buffer(int y, int x)
{
    for (int i = 0; i < buf.size(); i++)
    {
        if (buf[i].x == x && buf[i].y == y)
        {
            buf.erase(buf.begin() + i);
        }
    }
}

void File::save_to_buffer(int s, int y, int x)
{
    changed = true;
    buf.push_back({s, y, x});
}

void File::save_to_buffer_default(int s, int y, int x)
{
    buf.push_back({s, y, x});
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
        for (int i = 0; i <= buf.size(); i++)
        {
            Context::dev_log.write_to_file_chr(buf[i].symbol);
            fprintf(file, "%c", buf[i].symbol);
        };
    }
};

void File::close_file()
{
    if (file != NULL)
    {
        fclose(file);
    }
};

void File::save_default()
{
    if (!changed && !buf.empty())
        for (int i = 0; i <= buf.size(); i++)
        {
            fprintf(file, "%c", buf[i].symbol);
        }
};