#pragma once

#include <list>
#include <vector>
#include <string>
#include <stdio.h>
#include "./../file.hpp"

class ExecFile : public Open, public Read, public Save, public AutoSave, public Close
{
protected:
    std::string file_name;
    FILE *file;

public:
    void open(void *);

    std::string read();

    void save();

    void auto_save();

    void close();
};

extern ExecFile _EXEC_FILE;
