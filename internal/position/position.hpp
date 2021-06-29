#pragma once

#include <ncurses.h>
#include <tuple>

class PositionMove
{
private:
    std::tuple<int, int> move;
    bool empty = true;

public:
    void set_move(int y, int x);

    std::tuple<int, int> get_move();

    bool is_empty();
};

class Position : public PositionMove
{
private:
    int curr_y, curr_x;
    int max_y, max_x;

public:
    std::tuple<int *, int *> get_max_coords();

    std::tuple<int *, int *> get_curr_coords();

    void resetx();

    void decx();

    void decy();

    void incx();

    void setx(int x);

    void incy();
};

extern Position _POSITION;
