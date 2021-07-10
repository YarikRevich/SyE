#include <yaml.h>
#include <stdio.h>
#include <iostream>
#include "config.hpp"
#include <sys/stat.h>

#ifdef __APPLE__
#include <filesystem>
namespace fs = std::filesystem;
#elif defined(linux)
#include <experimental/filesystem>
namespace fs = std::experimental::filesystem;
#endif

void Config::open(void *)
{
    struct stat info;
    if (stat("~/.sye_configs", &info) == 0)
    {
        for (const auto &file : fs::directory_iterator("~/.sye_configs"))
        {
            const std::string path = file.path();
            this->configs.push_back(fopen(path.c_str(), "r"));
        }
        return;
    };
    mkdir("~/.sye_configs", 0755);
};

ConfigData Config::read_config()
{
    return {
        yaml_parser_parse()
    };
};

void Config::close()
{
    for (const auto &file : this->configs)
    {
        fclose(file);
    }
};