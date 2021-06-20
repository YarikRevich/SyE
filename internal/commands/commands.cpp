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
    char res[commands.size()];
    for (int i = 0; i < commands.size(); i++)
    {
        res[i] = commands[i];
    }
    return res;
};

void CommandTools::delete_command()
{
    commands.clear();
};

void CommandTools::pop_symbol_from_command()
{
    if (commands.size() != 0)
    {
        commands.pop_back();
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