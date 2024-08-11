#include "helper.hpp"

std::string IOHelper::getAbsolutePath(std::string path) noexcept {
    if (std::regex_search(path, std::regex(HOME_DIRECTORY_SHORT_REGEX))) {
        return std::regex_replace(path, std::regex(HOME_DIRECTORY_SHORT_REGEX), std::string(getenv(HOME_ENVIRONMENT_VARIABLE)).append(SLASH_SYMBOL));
    }

    if (!std::regex_search(path, std::regex(ROOT_DIRECTORY_SHORT_REGEX))) {
        return std::filesystem::current_path() / path;
    }

    return path;
};

std::string IOHelper::getFileExtension(const std::string& path) noexcept {
    std::string extension = fs::path(path).extension();

    if (extension.empty()) {
        return THEME_EXTENSION_NONE;
    }

    return extension.substr(1);
};