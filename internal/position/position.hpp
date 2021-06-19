#include <ncurses.h>
#include <tuple>

namespace Position
{
    //It's a namespace for positioning

    extern int curr_y, curr_x;
    extern int max_y, max_x;

    std::tuple<int, int> get_max_coords();

    int getx();

    void resetx();

    int gety();

    void set_max_coords();

    void update_curr_pos();

    void decx();

    void decy();

    void incx();

    void incy();
};
