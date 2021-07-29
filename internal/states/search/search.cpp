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

void SearchStateUpHandler::use()
{
    auto prev_cell = _SEARCH__BUF->getPrevCellByCoords(Coords::curr_y, Coords::curr_x);
    Coords::setY(prev_cell->coords.y), Coords::setX(prev_cell->coords.x);
};

void SearchStateDownHandler::use()
{
    auto next_cell = _SEARCH__BUF->getNextCellByCoords(Coords::curr_y, Coords::curr_x);
    Coords::setY(next_cell->coords.y), Coords::setX(next_cell->coords.x);
};

void SearchStateEnterHandler::use()
{
    EditorStatus::setCurrStatus(INSERT);
};

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
        SearchStateUpHandler::use();
        break;
    }
    case KEY_DOWN:
    {
        SearchStateDownHandler::use();
        break;
    }
    case K_ENTER:
    {
        SearchStateEnterHandler::use();
    }
    };
};