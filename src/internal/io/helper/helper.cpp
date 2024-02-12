#include "helper.hpp"

#include <iostream>

std::string IOHelper::getAbsolutePath(std::string path) noexcept {
    if (std::regex_search(path, std::regex("^~/"))) {
        return std::regex_replace(path, std::regex("^~/"), std::string(getenv("HOME")).append("/"));
    }

    if (!std::regex_search(path, std::regex("^/"))) {
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