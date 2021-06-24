#include <ncurses.h>
#include <string>
#include <cstring>
#include <vector>
#include "./../colors/colors.hpp"
#include "./../context/context.hpp"
#include "commands.hpp"

void CommandTools::set_command(char s)
{
    command.push_back(s);
};

std::string CommandTools::get_command()
{
    return command;
};

void CommandTools::delete_command()
{
    if (!command.empty())
    {
        command.clear();
    }
};

void CommandTools::pop_symbol_from_command()
{
    if (!command.empty())
    {
        if (command.size() != 0)
        {
            command.pop_back();
        }
    }
};

void CommandTools::apply_command(std::string c)
{
    if (c == "set color blue")
    {
        set_color(BLUE);
        refresh();
    }
    else if (c == "set color default")
    {
        set_color(DEFAULT);
        refresh();
    }
    else if (c == "w")
    {
        Context::file.write_to_file();
    };
};