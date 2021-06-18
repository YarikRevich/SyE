#include <ncurses.h>
#include <string>
#include <vector>
#include "colors.h"

std::vector<char> commands;
class CommandTools
{

    void set_command(char s)
    {
        commands.push_back(s);
    };

    std::string get_command()
    {
        return std::string(commands.data());
    };

    void delete_command()
    {
        commands.clear();
    };

    void pop_symbol_from_command()
    {
        commands.pop_back();
    };

    void apply_command(std::string c)
    {
        if (c == "set color blue")
        {
            set_color(BLUE);
            refresh();
        }
        else if (c == "w")
        {
            f::write_to_file();
        };
    };
};