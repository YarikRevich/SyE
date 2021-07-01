#include "search.hpp"
#include <ncurses.h>
#include <vector>
#include <tuple>
// #include "./../../../../status/status.hpp"
// #include "./../../../../bufs/search_buf/search_buf.hpp"
// #include "./../../../../file/file.hpp"
#include "./../pool.hpp"

void Search_Command::execute()
{
    // auto buf = _FILE.get();
    // auto command = _COMMAND_TOOL.get_command();
    // command.erase(command.begin());

    // std::vector<std::tuple<int, int>> found = {};

    // int sum = 0;
    // int curr_index = 0;
    // for (int i = 0; i <= buf.size(); i++)
    // {
    //     if (sum == command.size())
    //     {
    //         sum = 0;
    //         curr_index = 0;
    //         found.push_back({buf[i - 1].y, buf[i - 1].x});
    //     }
    //     if (buf[i].symbol == command[curr_index])
    //     {
    //         sum++;
    //         curr_index++;
    //     }
    //     else
    //     {
    //         sum = 0;
    //         curr_index = 0;
    //     }
    // };
    // auto [y, x] = found[found.size() - 1];
    // wmove(stdscr, y, x+1);

    // if (found.size() > 1)
    // {
    //     _STATE.set_state(SEARCH);
    // }

    // _SEARCH_BUF.set_buf(found);
}