#include "time.hpp"
#include <time.h>
#include <thread>
#include <ncurses.h>
#include "../../bufs/bufs.hpp"
#include "../../position/position.hpp"

void Time::use()
{
    using namespace std::literals::chrono_literals;
    for (;;)
    {
        const auto &now = std::chrono::system_clock::now();
        const auto &time_now = std::chrono::system_clock::to_time_t(now);
        const auto &lt = localtime(&time_now);

        char buff[50];
        strftime(buff, sizeof(buff), "%r", lt);

        mvwprintw(stdscr, Coords::max_y - 1, Coords::max_x - 12, buff);

        wmove(stdscr, Coords::curr_y, Coords::curr_x);
        wrefresh(stdscr);

        std::this_thread::sleep_for(2s);
    }
}