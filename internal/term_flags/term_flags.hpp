#pragma once

#include <string>
#include <vector>

namespace TermFlags
{
    extern int n_argc;
    extern char **n_argv;

    extern std::vector<std::string> n_single_flags;

    void add_args(int argc, char **argv);
    bool check_single_flag(std::string flag);
    bool last_is_flag();
    void check_exclude_syntax_highlighting_flag();
    void check_executive_flag();
    void check_dev_flag();
};