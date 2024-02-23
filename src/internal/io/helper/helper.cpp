#include "helper.hpp"

#include <iostream>

/**
 * Describes pre-defined default name of the environment variable used
 * to represent home path for the used user.
*/
#define HOME_ENVIRONMENT_VARIABLE "HOME"

/**
 * Describes pre-defined home directory regex definition
*/
#define HOME_DIRECTORY_SHORT_REGEX "^~/"

/**
 * Describes pre-defined root directory regex definition
*/
#define ROOT_DIRECTORY_SHORT_REGEX "^/"

/**
 * Describes pre-defined slash symbol
*/
#define SLASH_SYMBOL "/"

std::string IOHelper::getAbsolutePath(std::string path) noexcept {
    if (std::regex_search(path, std::regex(HOME_DIRECTORY_SHORT_REGEX))) {
        return std::regex_replace(path, std::regex(HOME_DIRECTORY_SHORT_REGEX), std::string(getenv(HOME_ENVIRONMENT_VARIABLE)).append(SLASH_SYMBOL));
    }

    if (!std::regex_search(path, std::regex(ROOT_DIRECTORY_SHORT_REGEX))) {
        return std::filesystem::current_path() / path;
    }

    return path;
};

std::string IOHelper::getFileExtension(std::string path) noexcept {
    std::string extension = fs::path(path).extension();

    if (extension.empty()) {
        return THEME_EXTENSION_NONE;
    }

    return extension.substr(1);
};