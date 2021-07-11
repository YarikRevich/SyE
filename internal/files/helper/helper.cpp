#include <iostream>
#include <ncurses.h>
#include "./../exec/exec.hpp"
#include "./../log/log.hpp"

void close_all_files(int)
{
    _EXEC_FILE->auto_save();
    _EXEC_FILE->close();
    _LOG_FILE->close();
    endwin();
    exit(0);
};