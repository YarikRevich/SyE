#pragma once

#include <string>
#include <regex>

#include <boost/filesystem.hpp>
#ifdef __APPLE__
#include <filesystem>
namespace fs = std::filesystem;
#elif defined(__linux__)
#include <experimental/filesystem>
namespace fs = std::experimental::filesystem;
#endif

#include <openssl/md5.h>
#include <iomanip>
#include <sstream>
#include <boost/iostreams/device/mapped_file.hpp>

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

/**
 * Represents helper used for IO operations.
*/
class IOHelper {
public:
    /**
     * Transforms given path to the absolute form.
     * 
     * @param path - given path to be transformed.
     * @return result of the transformation.
    */
    static std::string getAbsolutePath(std::string path) noexcept;

    /**
     * Retrieves file extension at the given location.
     * 
     * @param path - given location of the file.
     * @return given file extension.
    */
    static std::string getFileExtension(const std::string& path) noexcept;

    /**
     * Checks if given file exists at the given location.
     *
     * @param path - given location of the file.
     * @return result of the check.
    */
    static bool getFileExists(const std::string& path) noexcept;

    /**
     * Retrieves file content hash at the given location.
     *
     * @param path - given location of the file.
     * @return calculated file content hash.
    */
    static std::string getFileContentHash(const std::string& path) noexcept;
};