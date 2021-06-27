#pragma once

#include <iostream>
#include <string>
#include <stdio.h>
#include <list>

class DevLog
{
private:
    FILE *file;

public:
    void prepare_file();

    void write_to_file_str(std::list<std::string>);

    void write_to_file_chr(char);

    FILE *get_file();

    void close_file();
};

extern DevLog _DEV_LOG;