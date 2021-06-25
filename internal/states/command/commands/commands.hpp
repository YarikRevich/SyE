#pragma once

#include <vector>
#include <string>

class CommandInterface
{
public:
    virtual void execute();
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