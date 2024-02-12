#pragma once

#include <yaml-cpp/yaml.h>
#include <boost/filesystem.hpp>
#ifdef __APPLE__
#include <filesystem>
namespace fs = std::filesystem;
#elif defined(__linux__)
#include <experimental/filesystem>
namespace fs = std::experimental::filesystem;
#endif

#include <string>

#include "../../helper/helper.hpp"
#include "../../../logger/logger.hpp"

/**
 * Represents loader of the theme configuration files.
*/
class ThemeLoader {
public:
    /**
     * Loads configuration files at the given location.
     * 
     * @param root - given configuration files location root.
     * @return result of the configuration loader execution.
    */
    static int process(std::string extension, std::string root);
};