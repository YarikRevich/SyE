#include "dev.hpp"

void DevLog::prepare_file()
{
    file = fopen("log/dev.log", "a");
    setbuf(file, NULL);
}

void DevLog::write_to_file(const char s[])
{
    if (file != NULL)
    {
        fprintf(file, "%s", s);
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
