#pragma once

#include <tuple>
#include <vector>

namespace PreviouslyPressedHistory{
    extern int y, x;

    void set(int y, int x);
}    ;  

namespace PreviousMaxCoords {
    extern int max_y, max_x;

    void set(int max_y, int max_x);
}