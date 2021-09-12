#include "win_resizer.hpp"
#include "./../position.hpp"
#include "./../../bufs/bufs.hpp"
#include "./../../render/render.hpp"
#include "./../../history/history.hpp"

bool Resizer::areMaxCoordsChanged()
{
    return PressHistoryMaxCoords->y != Coords::max_y || PressHistoryMaxCoords->x != Coords::max_x;
};

ResizeType Resizer::getResizeType()
{
    if (PressHistoryMaxCoords->y != Coords::max_y)
    {
        return ResizeType::Y;
    }
    return ResizeType::X;
};

void Resizer::resizeWin()
{
    clear();
    if (this->getResizeType() == ResizeType::Y)
    {

        //     //translocate insert buf
    }
    else
    {
        _INSERT__BUF->translocateRowsLeft();
    }

    _RENDERER->rerender_insert_forcely();

    auto &&last_y = _INSERT__BUF->getLastY();
    move(last_y, _INSERT__BUF->getLastXInRow(last_y));
};

Resizer *_WIN_RESIZER = new Resizer;
