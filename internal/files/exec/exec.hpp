#pragma once

#include <list>
#include <vector>
#include <string>
#include <stdio.h>
#include "./../../index.hpp"

class ExecFile : public FileInterface, AddonFileInterface
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

extern ExecFile _EXEC_FILE;
