#pragma once

#include "./../types/types.hpp"
#include <stdio.h>
#include <vector>
#include <list>
#include <string>

class FileBuffer
{
protected:
    std::vector<char> default_buf;
    std::vector<buf_cell> buf;

    //Indicates if file is modified
    bool modified;

public:
    void erase(int y, int x);

    void add(int s, int y, int x);

    std::vector<buf_cell> get();
};

class FileHelper : public FileBuffer
{

protected:
    bool is_buf_equal_to_default();

    bool exist_in_buf(int y);
};

class FileBase : public FileHelper
{
protected:
    std::string file_name;
    FILE *file;

public:
    void open(char n[]);

    std::string read();

    void save();

    void auto_save();

    void close();
};

extern FileBase _FILE;
