#include <ncurses.h>
#include <tuple>
#include "position.hpp"
#include "./../log/dev/dev.hpp"

std::tuple<int *, int *> Position::get_max_coords()
{
	getmaxyx(stdscr, max_y, max_x);
	return {&max_y, &max_x};
};

std::tuple<int *, int *> Position::get_curr_coords()
{
	getyx(stdscr, curr_y, curr_x);
	return {&curr_y, &curr_x};
};

void PositionMove::set_move(int y, int x)
{
	if (this->empty)
	{
		this->empty = FALSE;
	}
	this->move = {y, x};
};

std::tuple<int, int> PositionMove::get_move()
{
	return this->move;
}

bool PositionMove::is_empty()
{
	return this->empty;
}

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

void Position::setx(int x)
{
	curr_x = x;
}

void Position::incy()
{
	++curr_y;
};

Position _POSITION;
