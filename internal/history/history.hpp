#pragma once

#include <vector>
#include <tuple>

typedef struct
{
    //Contains coords to init cell in history

    int y;
    int x;
} p_cell;

class PrevHistory
{
private:
    int prev_y, prev_x;

public:
    std::tuple<int, int> get_prev_yx();

    void set_prev_yx(int y, int x);
};

class PressedHistory
{
private:
    std::vector<p_cell> pressed;

public:
    void set_pressed(int y, int x);
    void delete_pressed(int y, int x);

    //Due to the history it choses the best x to move the pointer
    //during the moving up and down
    int get_best_x(int y);
};
