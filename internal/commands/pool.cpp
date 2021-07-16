#include <vector>
#include <string>
#include <cstring>
#include <ncurses.h>
#include "w/w.hpp"
#include "pool.hpp"
#include "search/search.hpp"
#include "./../status/status.hpp"
#include "set_insert_color/set_insert_color.hpp"
#include "./../bufs/bufs.hpp"

void apply_command(std::string c)
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
    else if (c.find("set insert color") != std::string::npos || c.find("sic") != std::string::npos)
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

        Set_Insert_Color_Command set_insert_color_com;
        set_insert_color_com.execute_with_params({found[found.size() - 1]});
    };
};