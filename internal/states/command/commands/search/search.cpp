#include "search.hpp"
#include <ncurses.h>
#include <valarray>
#include "./../../../../log/dev/dev.hpp"
#include "./../../../../file/file.hpp"
#include "./../commands.hpp"

void Search_Command::execute()
{
    auto buf = _FILE.get_buf();
    auto command = _COMMAND_TOOL.get_command();
    command.erase(command.begin());

    int sum = 0;
    int curr_index = 0;
    for (int i = 0; i < buf.size(); i++)
    {
        if (sum == command.size())
        {
            wmove(stdscr, buf[i - 1].y, buf[i - 1].x);
            break;
        }
        if (buf[i].symbol == command[curr_index])
        {
            sum++;
            curr_index++;
        }
        else
        {
            sum = 0;
            curr_index = 0;
        }
    };
}