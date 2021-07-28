#include <stdlib.h>
#include <ncurses.h>
#include "search.hpp"
#include "./../../bufs/bufs.hpp"
#include "./../../keys/keys.hpp"
#include "./../common/common.hpp"
#include "./../common/helper/helper.hpp"
#include "./../../position/position.hpp"
#include "./../../editor_status/editor_status.hpp"

int *SearchStateStorage::g_ch = (int *)std::malloc(sizeof(int));

void SearchStateUpHandler::use(){};

void SearchStateDownHandler::use(){};

void SearchStateLeftHandler::use(){};

void SearchStateRightHandler::use(){};

void SearchStateEnterHandler::use(){};

SearchState::SearchState(int ch)
{
    *SearchStateStorage::g_ch = ch;
};

void SearchState::use()
{
    switch (*SearchStateStorage::g_ch)
    {
    case KEY_UP:
    {
        CommonStateHelper::setKeyHandled(KEY_UP);
        break;
    }
    case KEY_DOWN:
    {
        CommonStateHelper::setKeyHandled(KEY_DOWN);
        break;
    }
    case KEY_LEFT:
    {
        CommonStateHelper::setKeyHandled(KEY_LEFT);
        break;
    }
    case KEY_RIGHT:
    {
        CommonStateHelper::setKeyHandled(KEY_RIGHT);
        break;
    }
    case K_ENTER:
    {
        EditorStatus::setCurrStatus(INSERT);
    }
    };
};

// void SearchHandler::handle(int ch)
// {
//     // auto [curr_y, curr_x] = _POSITION.get_curr_coords();

//     //auto buf = _SEARCH_BUF.get_buf();
//     // switch (ch)
//     // {
//     // case KEY_UP:
//     //     set_handled_status(KEY_UP);
//     //     for (int i = 0; i < buf.size(); i++)
//     //     {
//     //         auto [y, x] = buf[i];
//     //         if (y < *curr_y)
//     //         {
//     //             wmove(stdscr, y, x + 1);
//     //             break;
//     //         }
//     //     }
//     //     break;
//     // case KEY_DOWN:
//     //     set_handled_status(KEY_DOWN);
//     //     for (int i = 0; i < buf.size(); i++)
//     //     {
//     //         auto [y, x] = buf[i];
//     //         if (y > *curr_y)
//     //         {
//     //             wmove(stdscr, y, x + 1);
//     //             break;
//     //         }
//     //     }
//     //     break;
//     // case KEY_LEFT:
//     //     set_handled_status(KEY_LEFT);
//     //     break;
//     // case KEY_RIGHT:
//     //     set_handled_status(KEY_RIGHT);
//     //     break;
//     // case K_ENTER:
//     //     _STATE.set_state(INSERT);
//     // }
// }