#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <ncurses.h>
#include <stdio.h>
#include "files.hpp"

void File::prepare_file(char n[])
{
    file = fopen(n, "rw");
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
    buf.push_back({s, y, x});
}

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
    }
    return res;
}

void File::write_to_file()
{
    if (file != NULL)
    {
        for (const auto i : buf)
        {
            printw("%c\n", i.symbol);
            fprintf(file, "%c", i.symbol);
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