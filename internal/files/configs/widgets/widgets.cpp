#include "widgets.hpp"
#include <yaml-cpp/yaml.h>

#ifdef __APPLE__
#include <filesystem>
namespace fs = std::filesystem;
#elif defined(__linux__)
#include <experimental/filesystem>
namespace fs = std::experimental::filesystem;
#endif

template <typename T>
void WidgetsConfig<T>::open()
{
    auto config_path = PathsManagment::get_path_for_config_directory("widgets");
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
void WidgetsConfig<T>::read()
{
    for (const auto &file : this->files)
    {
        YAML::Node config = YAML::LoadFile(file);

        if (!config["enabled_widgets"].IsDefined())
        {
            // MessageWriter({RedPrinter({file, "does not contain insert"})});
        }
        auto enabled_widgets = config["enabled_widgets"].as<std::vector<std::string>>();

        for (const auto &widget : enabled_widgets)
        {
            this->data.enabled_widgets.push_back(widget);
        }
    };
};

template <typename T>
void WidgetsConfig<T>::open_and_read()
{
    this->open();
    this->read();
};

template <typename T>
T WidgetsConfig<T>::get()
{
    return this->data;
};

template class WidgetsConfig<WidgetConfigData>;

WidgetsConfig<WidgetConfigData> _WIDGETS_CONFIG;
