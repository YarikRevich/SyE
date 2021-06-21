#include <string>
#include "term_flags.hpp"
#include <iostream>
#include <filesystem>
#include "./../context/context.hpp"

TermFlags::TermFlags(int argc, char **argv)
{
    this->argc = argc;
    this->argv = argv;
};

bool TermFlags::check_single_flag(std::string flag)
{

    for (int i = 0; i < this->argc; i++)
    {
        if (this->argv[i] == ("--" + flag))
        {
            return true;
        };
    }
    return false;
};

void TermFlags::check_executive_flag()
{
    //Check if user has passed executive file;

    if (argc == 1 || !std::filesystem::exists(argv[argc - 1]))
    {
        std::cout << "\033[31m"
                  << "You gotta write the executive file"
                  << "\033[0m" << std::endl;
        exit(0);
    };

    Context::file.prepare_file(argv[argc - 1]);
};

void TermFlags::check_dev_flag()
{
    //Checks if user passed dev flag for debug;

    if (check_single_flag("dev"))
    {
        Context::dev_log.prepare_file();
    };
};