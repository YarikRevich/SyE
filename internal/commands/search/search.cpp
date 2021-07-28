#include <tuple>
#include <vector>
#include <ncurses.h>
#include <string>
#include "search.hpp"
#include "./../../bufs/bufs.hpp"
#include "./../../position/position.hpp"
#include "./../../editor_status/editor_status.hpp"

void Search_Command::execute_with_params(std::string search_word)
{
    for (auto i : search_word)
    {
        _LOG__BUF->addCellWithSymbolType(i, CHAR);
    };

    auto insert_buffer = _INSERT__BUF->getBufAsStringWithYCoord();
    for (int i = 0; i < insert_buffer.size(); i++)
    {
        size_t pos = insert_buffer[i].text.find(search_word);
        if (pos != insert_buffer[i].text.npos)
        {
            _SEARCH__BUF->addCellOnlyWithCoords(insert_buffer[i].y, pos + search_word.length());
        };
    };

    auto search_buffer = _SEARCH__BUF->getBufferIterator();

    if (search_buffer.size() >= 1)
    {
        auto last_cell = search_buffer[search_buffer.size() - 1];
        Coords::setY(last_cell->coords.y), Coords::setX(last_cell->coords.x);

        EditorStatus::setCurrStatus(SEARCH);
    }
}