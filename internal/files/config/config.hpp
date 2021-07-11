#pragma once

#include <map>
#include <string>
#include "./../file.hpp"

class Config : public Open, public ConfigReader, public ConfigBase, public FileBase
{
public:
    void open(void * n = NULL);
    void read_config();
    void close();
};

extern Config *_CONFIG_FILE;