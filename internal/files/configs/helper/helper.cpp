#include <map>
#include <pwd.h>
#include <string>
#include <vector>
#include <stdio.h>
#include <unistd.h>
#include <iostream>
#include <algorithm>
#include "helper.hpp"
#include <type_traits>
#include "./../../file.hpp"
#include "./../../exec/exec.hpp"
#include <boost/filesystem.hpp>
#include "./../../../bufs/bufs.hpp"
#include <boost/algorithm/string.hpp>

#ifdef __APPLE__
#include <filesystem>
namespace fs = std::filesystem;
#elif defined(linux)
#include <experimental/filesystem>
namespace fs = std::experimental::filesystem;
#endif

std::vector<std::string> PathsManagment::get_split_file_path(std::string file_path)
{
    std::vector<std::string> result;
    boost::split(result, file_path, boost::is_any_of("/"));
    return result;
};

std::string PathsManagment::get_file_extension(std::string split_file_path)
{
    std::vector<std::string> split_file_name;
    boost::split(split_file_name, split_file_path, boost::is_any_of("."));
    return split_file_name[split_file_name.size() - 1];
};

std::string PathsManagment::get_path_for_config_directory(std::string dest)
{
    struct passwd *pw = getpwuid(getuid());
    return std::string(pw->pw_dir) + "/.sye_configs" + "/" + dest;
};

void *ParseManagement::get_value_of(std::map<std::string, void *> storage, std::string key)
{
    if (storage.count(key))
    {
        return storage[key];
    }

    return NULL;
};

std::string ParseManagement::transform_string_to_lower(std::string src)
{
    std::string result = src;
    std::transform(result.begin(), result.end(), result.begin(), [](char n)
                   { return std::tolower(n); });
    return result;
};