#include "z.hpp"
#include "./../../bufs/bufs.hpp"
#include "./../../position/position.hpp"

void Z_Command::execute() const
{
    auto [y, x] = _INSERT__BUF->deleteWordBeforeSpace(Coords::curr_y, Coords::curr_x);
    Coords::setY(y); Coords::setX(x);
    

}