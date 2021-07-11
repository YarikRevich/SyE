#include <string>
#include <cstring>
#include <iostream>
#include "term_flags.hpp"
#include "./../bufs/bufs.hpp"
#include "./../files/log/log.hpp"
#include "./../files/exec/exec.hpp"
#include "./../files/config/config.hpp"

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
    this->check_exclude_syntax_highlighting_flag();
    this->check_executive_flag();
    this->check_dev_flag();
};

bool TermFlags::check_single_flag(std::string flag)
{

    for (int i = 0; i < this->argc; i++)
    {
        if (std::strcmp(this->argv[i], flag.c_str()) == 0){
            return true;
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

void TermFlags::check_exclude_syntax_highlighting_flag()
{
    if (!this->check_single_flag("--e"))
    {
        _CONFIG_FILE->open();
    }
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

    _EXEC_FILE->open(argv[argc - 1]);
};

void TermFlags::check_dev_flag()
{
    if (check_single_flag("--dev"))
    {
        _LOG_FILE->open(NULL);
    };
};