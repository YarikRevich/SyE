#pragma once

#include <stdio.h>
#include <vector>
#include <list>
#include <string>

typedef struct
{
    int symbol;
    int y;
    int x;
} buf_cell;

class File
{
private:
    std::vector<buf_cell> buf;
    FILE *file;

public:
    void prepare_file(char n[]);

    void delete_from_buffer(int y, int x);

    void save_to_buffer(int s, int y, int x);

    std::string read_from_file();

    void write_to_file();

    void close_file();
};
