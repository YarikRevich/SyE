#include <tuple>
#include <vector>
#include <ncurses.h>
#include <string>
#include "search.hpp"
#include "./../../bufs/bufs.hpp"
#include "./../../editor_status/editor_status.hpp"

void Search_Command::execute_with_params(std::string search_word)
{
    auto buffer = _INSERT__BUF->getBufAsStringWithYCoord();
    for (int i = 0; i < buffer.size(); i++){
        if (buffer[i].text.find(search_word) != buffer[i].text.npos){
            // _SEARCH__BUF->
        }
    };
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
    EditorStatus::setCurrStatus(SEARCH);

}