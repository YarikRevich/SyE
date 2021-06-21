#pragma once

#include <string>

class TermFlags
{
private:
    int argc;
    char **argv;

public:
    TermFlags(int argc, char **argv);
    bool check_single_flag(std::string flag);
    void check_executive_flag();
    void check_dev_flag();
};