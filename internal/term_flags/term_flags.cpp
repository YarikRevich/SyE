#include <string>
#include <cstring>
#include "term_flags.hpp"
#include <iostream>
#include "./../log/dev/dev.hpp"
#include "./../file/file.hpp"

#ifdef __APPLE__
#include <filesystem>
namespace fs = std::filesystem;
#elif defined(linux)
#include <experimental/filesystem>
namespace fs = std::experimental::filesystem;
#endif

TermFlags::TermFlags(int argc, char **argv)
{
    this->argc = argc;
    this->argv = argv;
};

bool TermFlags::check_single_flag(std::string flag)
{

    for (int i = 0; i < this->argc; i++)
    {
        for (int q = 0; i <= single_flags.size(); i++)
        {
            if (std::strcmp(this->argv[i], single_flags[q].c_str()) == 0)
            {
                return true;
            };
        }
    }
    return false;
};

bool TermFlags::last_is_flag()
{
    for (int i = 0; i < single_flags.size(); i++)
    {
        if (std::strcmp(argv[argc - 1], single_flags[i].c_str()) == 0)
        {
            return true;
        }
    }
    return false;
};

void TermFlags::check_executive_flag()
{
    //Check if user has passed executive file;

    if (argc == 1 || last_is_flag())
    {
        std::cout << "\033[31m"
                  << "You gotta write executable file"
                  << "\033[0m" << std::endl;
        exit(0);
    }

    if (!fs::exists(argv[argc - 1]))
    {
        fclose(fopen(argv[argc - 1], "w"));
    };

    _FILE.prepare_file(argv[argc - 1]);
};

void TermFlags::check_dev_flag()
{
    //Checks if user passed dev flag for debug;

    if (check_single_flag("--dev"))
    {
        _DEV_LOG.prepare_file();
    };
};