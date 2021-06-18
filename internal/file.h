#include <iostream>
#include <string>
#include <vector>
#include <ncurses.h>
#include <stdio.h>

typedef struct
{
    int symbol;
    int y;
    int x;
} buf_cell;

namespace f
{
    std::vector<buf_cell> buf;
    bool opened;
    FILE *file;

    void prepare_file(int argc, char **argv)
    {
        if (argc >= 2)
        {
            file = fopen(argv[1], "w");
            if (file != NULL)
            {
                opened = true;
            };
        }
    };

    void delete_from_buffer(int y, int x)
    {
        for (int i = 0; i < buf.size(); i++)
        {
            if (buf[i].x == x && buf[i].y == y)
            {
                buf.erase(buf.begin() + i);
            }
        }
    }

    void save_to_buffer(int s, int y, int x)
    {
        buf.push_back({s, y, x});
    }

    void write_to_file()
    {
        if (opened)
        {
            for (const auto i : buf)
            {
                fprintf(file, "%c", i.symbol);
            };
        }
    };

    void close_file()
    {
        if (opened)
        {
            fclose(file);
        }
    }
}