#include "theme_config.hpp"

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
        ;
    {
        auto split_file_path = this->get_split_file_path(file.path().c_str());
        auto file_extension = this->get_file_extension(split_file_path[split_file_path.size() - 1]);

        if (std::strcmp(file_extension, "yaml") == 0)
        {
            configs.push_back(file.path());
        }
    }
};

template <typename T>
void ThemeConfig<T>::read(){
    
};

template <typename T>
T ThemeConfig<T>::get()
{
    return this->data;
};

template class ThemeConfig<ThemeConfigData>;