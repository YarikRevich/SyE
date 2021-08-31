#include <string>
#include <cstring>
#include <iostream>
#include "term_flags.hpp"
#include "./../bufs/bufs.hpp"
#include "./../files/log/log.hpp"
#include "./../files/exec/exec.hpp"

#ifdef __APPLE__
#include <filesystem>
namespace fs = std::filesystem;
#elif defined(__linux__)
#include <experimental/filesystem>
namespace fs = std::experimental::filesystem;
#endif

int TermFlags::n_argc;
char **TermFlags::n_argv;
std::vector<std::string> TermFlags::n_single_flags = {
    "--log",
};

bool TermFlags::check_single_flag(std::string flag)
{

    for (int i = 0; i < n_argc; i++)
    {
        if (std::strcmp(n_argv[i], flag.c_str()) == 0)
        {
            return true;
        }
    }
    return false;
};

void TermFlags::add_args(int argc, char **argv)
{
    n_argc = argc;
    n_argv = argv;
};

bool TermFlags::last_is_flag()
{
    for (int i = 0; i < n_single_flags.size(); i++)
    {
        if (std::strcmp(n_argv[n_argc - 1], n_single_flags[i].c_str()) == 0)
        {
            return true;
        }
    }
    return false;
};

void TermFlags::check_executive_flag()
{
    //Check if user has passed executive file;
    if (n_argc == 1 || last_is_flag())
    {
        std::cout << "\033[31m"
                  << "You gotta write executable file"
                  << "\033[0m" << std::endl;
        exit(0);
    }

    if (!fs::exists(n_argv[n_argc - 1]))
    {
        fclose(fopen(n_argv[n_argc - 1], "w"));
    };

    _EXEC_FILE->open(n_argv[n_argc - 1]);
};

void TermFlags::check_dev_flag()
{
    if (check_single_flag("--log"))
    {
        _LOG_FILE->open(NULL);
    };
};