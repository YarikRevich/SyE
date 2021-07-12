#pragma once

#include <map>
#include <string>
#include "./../file.hpp"

class Config : public Open, public GetConfig, public ConfigReader, public ConfigBase, public FileBase
{
public:
    void open(void *n = NULL);
    void read_config();
    ConfigData getConfig();
};

extern Config *_CONFIG_FILE;