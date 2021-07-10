#pragma once

#include <map>
#include <string>
#include "./../file.hpp"

class Config : public Open, public ConfigReader, public Close, public ConfigBase, public FileBase
{
public:
    void open(void *);
    ConfigData read_config();
    void close();
};