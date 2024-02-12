#pragma once

#include <string>
#include <regex>

#ifdef __APPLE__
#include <filesystem>
namespace fs = std::filesystem;
#elif defined(__linux__)
#include <experimental/filesystem>
namespace fs = std::experimental::filesystem;
#endif

/**
 * Represents helper used for IO opereations.
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
    static std::string getFileExtension(std::string path) noexcept;
};