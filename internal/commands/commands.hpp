#pragma once

#include <vector>
#include <string>

class CommandInterface
{
    virtual void execute();
};

class CommandTools
{
private:
    std::vector<char> commands;

public:
    void set_command(char s);

    std::string get_command();

    void delete_command();

    void pop_symbol_from_command();

    void apply_command(std::string c);
};