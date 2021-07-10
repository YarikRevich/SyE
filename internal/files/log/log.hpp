#pragma once

#include <list>
#include <string>
#include <stdio.h>
#include <iostream>
#include "./../file.hpp"

class LogFile : public Open, public Read, public Save, public Close
{
protected:
    std::string file_name;
    FILE *file;

public:
    void open(void *);

    std::string read();

    void save();

    void close();
};

extern LogFile _LOG_FILE;