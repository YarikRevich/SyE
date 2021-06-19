#include <iostream>
#include <string>
#include <vector>
#include <ncurses.h>
#include <stdio.h>
#include "files.hpp"


void File::prepare_file(int argc, char **argv)
{
    if (argc >= 2)
    {
        file = fopen(argv[1], "w");
        if (file != NULL)
        {
            OPEN = true;
        };
    }
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

void File::write_to_file()
{
    if (OPEN)
    {
        for (const auto i : buf)
        {
            fprintf(file, "%c", i.symbol);
        };
    }
};

void File::close_file()
{
    if (OPEN)
    {
        fclose(file);
    }
};