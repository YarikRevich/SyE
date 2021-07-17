#pragma once

#include <map>
#include <string>
#include <vector>
#include "./../file.hpp"

namespace PathsManagment
{
    std::vector<std::string> get_split_file_path(std::string file_path);

    std::string get_file_extension(std::string split_file_path);

    std::string get_path_for_config_directory(std::string dest);
};

namespace ParseManagement
{
    void *get_value_of(std::map<std::string, void *> storage, std::string key);

    std::string transform_string_to_lower(std::string src);
};

template <typename T>
class ConfigInterface
{
private:
    std::vector<std::string> files;
    T data;

public:
    virtual void open() = 0;
    virtual void read() = 0;
    virtual T get() = 0;
};