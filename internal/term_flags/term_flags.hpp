#pragma once

#include <string>
#include <vector>

class TermFlags
{
private:
    std::vector<std::string> single_flags = {
        "--dev",
    };
    int argc;
    char **argv;

public:
    TermFlags(int argc, char **argv);
    bool check_single_flag(std::string flag);
    bool last_is_flag();
    void check_exclude_syntax_highlighting_flag();
    void check_executive_flag();
    void check_dev_flag();
};