#include <ncurses.h>
#include <tuple>
#include "position.hpp"

std::tuple<int*, int*> Position::get_max_coords()
{
	getmaxyx(stdscr, max_y, max_x);
	return {&max_y, &max_x};
};

std::tuple<int*, int*> Position::get_curr_coords()
{
	getyx(stdscr, curr_y, curr_x);
	return {&curr_y, &curr_x};
};

void Position::resetx()
{
	curr_x = 0;
}

void Position::decx()
{
	--curr_x;
};
void Position::decy()
{
	--curr_y;
};
void Position::incx()
{
	++curr_x;
};
void Position::incy()
{
	++curr_y;
};

Position _POSITION;
