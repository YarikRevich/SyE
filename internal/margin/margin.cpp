#include <ncurses.h>
#include "margin.hpp"

bool CharInserter::is_between()
{
    auto const [curr_y, curr_x] = _POSITION.get_curr_coords();
    auto const [max_y, max_x] = _POSITION.get_max_coords();
    auto const buf = _INSERT__BUF.get();

    if (*curr_x != *max_x)
    {
        int left_x, right_x;
        bool left_x_found, right_x_found;
        for (int i = 0; i < buf.size(); i++)
        {
            if (buf[i].x == (*curr_x - 1))
            {
                left_x = buf[i].x;
                left_x_found = true;
            }
            else if (buf[i].x == (*curr_x + 1))
            {
                right_x = buf[i].x;
                right_x_found = true;
            }
        }
        return left_x_found && right_x_found;
    }
    else if (*curr_x == *max_x)
    {
        int left_x;
        bool left_x_found, curr_x_found;
        for (int i = 0; i < buf.size(); i++)
        {
            if (buf[i].x == (*curr_x - 1))
            {
                left_x = buf[i].x;
                left_x_found = true;
            }
            else if (buf[i].x == *curr_x)
            {
                curr_x_found = true;
            }
        }
        return left_x_found && curr_x_found;
    }
    else if (*curr_x == 0 && *curr_y != 0)
    {
        int right_x;
        bool right_x_found, curr_x_found;
        for (int i = 0; i < buf.size(); i++)
        {
            if (buf[i].x == (*curr_x + 1))
            {
                right_x = buf[i].x;
                right_x_found = true;
            }
            else if (buf[i].x == *curr_x)
            {
                curr_x_found = true;
            }
        }
        return right_x_found && curr_x_found;
    }
    else
    {
        return false;
    }
};