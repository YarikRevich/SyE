#include <pwd.h>
#include <string>
#include <vector>
#include <stdio.h>
#include <unistd.h>
#include <iostream>
#include <algorithm>
#include "config.hpp"
#include <yaml-cpp/yaml.h>
#include "./../exec/exec.hpp"
#include <boost/filesystem.hpp>
#include "./../../bufs/bufs.hpp"
#include <boost/algorithm/string.hpp>

#ifdef __APPLE__
#include <filesystem>
namespace fs = std::filesystem;
#elif defined(linux)
#include <experimental/filesystem>
namespace fs = std::experimental::filesystem;
#endif

void Config::open(void *n)
{
    struct passwd *pw = getpwuid(getuid());
    for (const auto &file : fs::directory_iterator(std::string(pw->pw_dir) + "/.sye_configs"))
    {
        std::vector<std::string> split_dir_path;
        boost::split(split_dir_path, file.path().c_str(), boost::is_any_of("/"));
        std::vector<std::string> split_file_name;
        boost::split(split_file_name, split_dir_path[split_dir_path.size() - 1], boost::is_any_of("."));
        if (std::strcmp(split_file_name[split_file_name.size() - 1].c_str(), "yaml") == 0)
        {
            configs.push_back(file.path());
        }
    }
};

void Config::read_config()
{
    //_LOG__BUF->addCellWithSymbolType('Y', CHAR);
    for (auto const file : this->configs)
    {
        YAML::Node config = YAML::LoadFile(file);
        if (config["extension"])
        {

            std::string file_name = _EXEC_FILE->getFileName();
            std::vector<std::string> split_file_name;
            boost::split(split_file_name, file_name, boost::is_any_of("."));
            std::string file_extension = split_file_name[split_file_name.size() - 1];

            std::vector<std::string> extensions = config["extension"].as<std::vector<std::string>>();

            // if (!extensions.empty() && std::find(extensions.begin(), extensions.end(), file_extension) != extensions.end()){
            //     _LOG__BUF->addCellWithSymbolType('I', CHAR);
            // }
            _LOG__BUF->addCellWithSymbolType(extensions.size(), INT);
        }
        // yaml_parser_initialize(&parser);
        // yaml_parser_set_input_file(&parser, file);

        // yaml_event_s event;
        // yaml_parser_parse(&parser, &event);

        // yaml_event_delete(&event);

        // yaml_parser_delete(&parser);
    }
};

Config *_CONFIG_FILE = new Config;