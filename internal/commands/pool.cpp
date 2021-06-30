#include <ncurses.h>
#include <string>
#include <cstring>
#include <vector>
#include "w/w.hpp"
#include "search/search.hpp"
#include "set_color/set_color.hpp"
#include "./../../../status/status.hpp"
#include "./../../../log/dev/dev.hpp"
#include "pool.hpp"

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
    std::transform(c.begin(), c.end(), c.begin(), [](char t)
                   { return tolower(t); });

    if (c == "w")
    {
        W_Command w_com;
        w_com.execute();
    }
    else if (c[0] == '/')
    {
        Search_Command search_com;
        search_com.execute();
    }
    else if (c.find("set color") != std::string::npos || c.find("st") != std::string::npos)
    {
        int pos = 0;
        std::vector<std::string> found;
        while ((pos = c.find(" ")) != std::string::npos)
        {
            std::string token = c.substr(0, pos);
            found.push_back(token);
            c.erase(0, pos + 1);
        }

        found.push_back(c);

        Set_Color_Command set_color_com;
        set_color_com.execute_with_params({found[found.size() - 1]});
    };
};

CommandTools _COMMAND_TOOL;