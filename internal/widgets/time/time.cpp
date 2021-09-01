#include "time.hpp"
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
        const auto &now_c = std::chrono::system_clock::to_time_t(now);
        const auto &now_tm = std::localtime(&now_c);

        char buff[sizeof(now_tm)];
        strftime(buff, sizeof(buff), "%I:%M%p.", now_tm);

        std::this_thread::sleep_for(2s);

        mvwprintw(stdscr, Coords::max_y-1, Coords::max_x-10, buff);
        wrefresh(stdscr);
    }
}