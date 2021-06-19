#include <ncurses.h>
#include <string>
#include <vector>
#include "./../colors/colors.hpp"
#include "./../context/context.hpp"
#include "commands.hpp"

void CommandTools::set_command(char s)
{
    commands.push_back(s);
};

std::string CommandTools::get_command()
{
    return std::string(commands.data());
};

void CommandTools::delete_command()
{
    commands.clear();
};

void CommandTools::pop_symbol_from_command()
{
    commands.pop_back();
};

void CommandTools::apply_command(std::string c)
{
    if (c == "set color blue")
    {
        set_color(BLUE);
        refresh();
    }
    else if (c == "w")
    {
        Context::file.write_to_file();
    };
};