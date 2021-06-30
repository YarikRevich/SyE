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

class CommandTools
{
private:
    std::string command;

public:
    void set_command(char s);

    std::string get_command();

    void delete_command();

    void pop_symbol_from_command();

    void apply_command(std::string c);
};

extern CommandTools _COMMAND_TOOL;