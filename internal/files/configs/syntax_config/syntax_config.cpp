#include <map>
#include <vector>
#include <csignal>
#include <yaml-cpp/yaml.h>
#include "syntax_config.hpp"
#include "./../helper/helper.hpp"
#include "./../../../messages/messages.hpp"
#include "./../../../files/exec/exec.hpp"

#ifdef __APPLE__
#include <filesystem>
namespace fs = std::filesystem;
#elif defined(linux)
#include <experimental/filesystem>
namespace fs = std::experimental::filesystem;
#endif

template <typename T>
void SyntaxConfig<T>::open()
{
    auto config_path = PathsManagment::get_path_for_config_directory("syntax");
    for (const auto &file : fs::directory_iterator(config_path))
    {
        auto split_file_path = PathsManagment::get_split_file_path(file.path().c_str());
        auto file_extension = PathsManagment::get_file_extension(split_file_path[split_file_path.size() - 1]);

        if (std::strcmp(file_extension.c_str(), "yaml") == 0)
        {
            this->files.push_back(file.path());
        }
    }
};

template <typename T>
void SyntaxConfig<T>::read()
{
    std::string file_name = _EXEC_FILE->getFileName();
    auto file_extension = PathsManagment::get_file_extension(file_name);

    for (auto const file : this->files)
    {
        YAML::Node config = YAML::LoadFile(file);

        if (!config["extension"].IsDefined())
        {
            // MessageWriter({RedPrinter({file, "does not contain extension"})});
        }
        if (!config["types"].IsDefined())
        {
            // MessageWriter({RedPrinter({file, "does not contain types"})});
        };

        auto extensions = config["extension"].as<std::vector<std::string>>();
        if (std::find(extensions.begin(), extensions.end(), file_extension) != extensions.end())
        {
            std::map<std::string, std::string> types = config["types"].as<std::map<std::string, std::string>>();
            if (types.empty()){
                continue;
            }

            SyntaxConfigCellData data;

            if (types.count("name"))
            {
                data.name = types["name"];
            };
            if (types.count("color"))
            {
                data.color = types["color"];
            };

            this->data.types.push_back(data);
            break;
        };
    };
};

template <typename T>
void SyntaxConfig<T>::open_and_read()
{
    this->open();
    this->read();
};

template <typename T>
T SyntaxConfig<T>::get()
{
    return this->data;
};

template class SyntaxConfig<SyntaxConfigData>;

SyntaxConfig<SyntaxConfigData> _SYNTAX_CONFIG;