#pragma once

#include <map>
#include <string>

class Config
{
private:
    std::map<std::string, bool> config_data;
    FILE *file;

public:
    void read();
    void save();
    void set_color(int c);
};