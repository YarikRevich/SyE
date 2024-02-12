#include "theme.hpp"

int ThemeLoader::process(std::string extension, std::string root) {
    std::string path = IOHelper::getAbsolutePath(fs::path(root) / fs::path(THEME_CONFIG_PATH));
    if (!boost::filesystem::exists(path)){
        Logger::SetError(THEME_DIRECTORY_NOT_FOUND_EXCEPTION);

        return EXIT_FAILURE;
    }

    fs::directory_iterator end;

    YAML::Node config;

    for (fs::directory_iterator iter(path); iter != end; ++iter) {
        config = YAML::LoadFile(iter->path());
    }

    // boost::filesystem::recursive_directory_iterator iter(path);

    // boost::filesystem::recursive_directory_iterator end;
    // while (iter != end) {
    //     boost::system::error_code error;

    //     iter.increment(error);

    //     if (error) {
    //         Logger::SetError(error.message());

    //         return EXIT_FAILURE;
    //     }
    // }

    return EXIT_SUCCESS;
}