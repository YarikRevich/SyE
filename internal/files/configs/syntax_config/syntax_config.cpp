#include <csignal>
#include "syntax_config.hpp"

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
        ;
    {
        auto split_file_path = this->get_split_file_path(file.path().c_str());
        auto file_extension = this->get_file_extension(split_file_path[split_file_path.size() - 1]);

        if (std::strcmp(file_extension, "yaml") == 0)
        {
            this->files.push_back(file.path());
        }
    }
};

template <typename T>
void SyntaxConfig<T>::read()
{
    std::string file_name = _EXEC_FILE->getFileName();
    auto file_extension = this->get_file_extension(file_name);

    for (auto const file : this->files)
    {
        YAML::Node config = YAML::LoadFile(file);

        if (!config["extension"].IsDefined() || !config["types"].IsDefined())
        {
            std::raise(SIGINT);
        }
        std::vector<std::string> extensions = config["extension"].as<std::vector<std::string>>();
        if (!extensions.empty() && std::find(extensions.begin(), extensions.end(), file_extension) != extensions.end())
        {
            configDataTypeCell dataToSave;

            dataToSave.name = this->get_value_of(types, "name");
            dataToSave.color = this->get_value_of(types, "color");
            this->configData.types.push_back(dataToSave);

            break;
        }
    }
}
}
;

template <typename T>
T SyntaxConfig<T>::get()
{
    return this->data;
};

template class SyntaxConfig<SyntaxConfigData>;