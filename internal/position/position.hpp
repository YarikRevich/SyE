#pragma once

#include <ncurses.h>
#include <tuple>

namespace Coords
{
    extern int curr_y, curr_x;
    extern int max_y, max_x;

    void updateMaxCoords();
    void updateCurrentCoords();

    void resetX();
    void setX(int x);
    void setY(int y);

    void decX();
    void decY();

    void incX();
    void incY();
};

namespace Position
{
    extern bool startOfY, startOfX;

    void resetPositionPoints();

    void setStartOfY(bool status);

    bool isStartOfY();

    void setStartOfX(bool status);

    bool isStartOfX();
};