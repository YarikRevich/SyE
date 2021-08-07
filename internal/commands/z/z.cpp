#include "z.hpp"
#include "./../../bufs/bufs.hpp"
#include "./../../position/position.hpp"

void Z_Command::execute()
{
    auto [x, y] = _INSERT__BUF->deleteWordBeforeSpace(Coords::curr_y, Coords::curr_x);
    _LOG__BUF->addCellWithSymbolType(y, INT);
    Coords::setY(y); Coords::setX(x);
}