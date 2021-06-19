#include <ncurses.h>
#include <tuple>
#include "position.hpp"

int Position::max_x = 0;
int Position::max_y = 0;
int Position::curr_x = 0;
int Position::curr_y = 0;

std::tuple<int, int> Position::get_max_coords()
{
	return {max_y, max_x};
};

int Position::getx()
{
	return curr_x;
};

void Position::resetx()
{
	curr_x = 0;
}

int Position::gety()
{
	return curr_y;
};

void Position::set_max_coords()
{
	getmaxyx(stdscr, max_y, max_x);
};

void Position::update_curr_pos()
{
	getyx(stdscr, curr_y, curr_x);
};

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
