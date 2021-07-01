#include <stdio.h>
#include "fstream"
#include "log.hpp"
#include "./../../bufs/bufs.hpp"

#ifdef __APPLE__
#include <filesystem>
namespace fs = std::filesystem;
#elif defined(linux)
#include <experimental/filesystem>
namespace fs = std::experimental::filesystem;
#endif

void LogFile::open(char *)
{
    fs::create_directory("log");
    std::ofstream f("log/dev.log");
    f.close();

    file = fopen("log/dev.log", "w");
    setbuf(file, NULL);
}

std::string LogFile::read()
{
    std::string res;
    if (this->file != NULL)
    {
        fseek(this->file, 0, SEEK_END);
        size_t size = ftell(this->file);
        res.resize(size);
        rewind(this->file);
        fread(&res[0], 1, size, this->file);
    }
    return res;
}

void LogFile::save()
{
    if (this->file != NULL)
    {
        auto const log_buf = _LOG__BUF.get();
        for (int i = 0; i < log_buf.size(); i++)
        {
            fprintf(this->file, "%c", log_buf[i]->symbol);
        }
        _LOG__BUF.clear();
    }
};

void LogFile::close()
{
    if (file != NULL)
    {
        fclose(file);
    }
};

LogFile _LOG_FILE;
