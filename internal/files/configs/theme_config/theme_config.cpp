#include <tuple>
#include <string>
#include <yaml-cpp/yaml.h>
#include "theme_config.hpp"
#include "./../helper/helper.hpp"
#include "./../../../files/exec/exec.hpp"

#ifdef __APPLE__
#include <filesystem>
namespace fs = std::filesystem;
#elif defined(linux)
#include <experimental/filesystem>
namespace fs = std::experimental::filesystem;
#endif

template <typename T>
void ThemeConfig<T>::open()
{
    auto config_path = PathsManagment::get_path_for_config_directory("theme");
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
void ThemeConfig<T>::read()
{
    std::string file_name = _EXEC_FILE->getFileName();
    auto file_extension = PathsManagment::get_file_extension(file_name);

    for (auto const file : this->files)
    {
        YAML::Node config = YAML::LoadFile(file);

        if (!config["insert"].IsDefined())
        {
            // MessageWriter({RedPrinter({file, "does not contain insert"})});
        }
        if (!config["effects"].IsDefined())
        {
            // MessageWriter({RedPrinter({file, "does not contain effects"})});
        };
        if (!config["command"].IsDefined())
        {
            // MessageWriter({RedPrinter({file, "does not contain command"})});
        };
        if (!config["effects"].IsScalar())
        {
            continue;
        }

        ThemeConfigData data;

        data.name = file;

        auto insert = config["insert"].as<std::vector<std::string>>();
        if (insert.empty() || insert.size() > 2 || insert.size() < 2)
        {
            continue;
        };

        data.insert = {
            ParseManagement::transform_string_to_lower(insert[0]),
            ParseManagement::transform_string_to_lower(insert[1])};

        auto command = config["command"].as<std::vector<std::string>>();
        if (insert.empty() || insert.size() > 2 || insert.size() < 2)
        {
            continue;
        };

        data.command = {
            ParseManagement::transform_string_to_lower(command[0]),
            ParseManagement::transform_string_to_lower(command[1])};

        data.effects = config["effects"].as<std::string>();

        this->data = data;
    };
};

template <typename T>
void ThemeConfig<T>::open_and_read()
{
    this->open();
    this->read();
};

template <typename T>
T ThemeConfig<T>::get()
{
    return this->data;
};

template class ThemeConfig<ThemeConfigData>;

ThemeConfig<ThemeConfigData> _THEME_CONFIG;