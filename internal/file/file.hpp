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
    std::vector<char> default_to_save;
    std::vector<buf_cell> buf;
    std::string file_name;
    FILE *file;

public:
    void prepare_file(char n[]);

    void delete_from_buffer(int y, int x);

    void save_to_buffer(int s, int y, int x);

    std::string read_from_file();

    bool is_buf_equal_to_default();

    void write_to_file();

    void close_file();

    void save_default();
};

extern File _FILE;
