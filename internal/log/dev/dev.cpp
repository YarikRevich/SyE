#include "dev.hpp"
#include "fstream"

#ifdef __APPLE__
#include <filesystem>
namespace fs = std::filesystem;
#elif defined(linux)
#include <experimental/filesystem>
namespace fs = std::experimental::filesystem;
#endif

void DevLog::prepare_file()
{
    fs::create_directory("log");
    std::ofstream f("log/dev.log");
    f.close();

    file = fopen("log/dev.log", "w");
    setbuf(file, NULL);
}

void DevLog::write_to_file_str(std::string s)
{
    if (file != NULL)
    {
        fprintf(file, "%s", s.c_str());
    }
};

void DevLog::write_to_file_chr(char s)
{
    if (file != NULL)
    {
        fprintf(file, "%c\n", s);
    }
};

FILE *DevLog::get_file()
{
    return file;
}

void DevLog::close_file()
{
    if (file != NULL)
    {
        fclose(file);
    }
};
