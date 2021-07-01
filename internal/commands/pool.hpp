#pragma once

#include <vector>
#include <string>

class CommandInterface
{
public:
    //Virtual method
    void execute();

    //Virtual method
    void execute_with_params(std::vector<std::string> params);
};

void apply_command(std::string c);