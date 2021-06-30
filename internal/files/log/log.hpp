#pragma once

#include <list>
#include <string>
#include <stdio.h>
#include <iostream>
#include "./../../index.hpp"

class LogFile : public FileInterface
{
protected:
    std::string file_name;
    FILE *file;

public:
    void open(char n[]);

    std::string read();

    void save();

    void close();
};

// class LogFile : public FileInterface
// {
// private:
//     FILE *file;

// public:
//     void prepare_file();

//     void write_to_file_str(std::list<std::string>);

//     void write_to_file_chr(char);

//     FILE *get_file();

//     void close_file();
// };

extern LogFile _LOG_FILE;