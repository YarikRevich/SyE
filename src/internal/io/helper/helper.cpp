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

bool IOHelper::getFileExists(const std::string &path) noexcept {
    return boost::filesystem::exists(path);
};

std::string IOHelper::getFileContentHash(const std::string& path) noexcept {
    unsigned char result[MD5_DIGEST_LENGTH];
    boost::iostreams::mapped_file_source src(path);
    MD5((unsigned char*)src.data(), src.size(), result);

    std::ostringstream sout;
    sout<<std::hex<<std::setfill('0');
    for(auto c: result) sout<<std::setw(2)<<(int)c;

    return sout.str();
}