#include <ncurses.h>
#include <tuple>
#include "position.hpp"

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

void PositionMove::delete_move()
{
	this->empty = TRUE;
	this->move = {};
};

bool PositionMove::is_empty()
{
	return this->empty;
}

void Position::resetx()
{
	this->curr_x = 0;
}

void Position::decx()
{
	this->curr_x--;
};
void Position::decy()
{
	this->curr_y--;
};
void Position::incx()
{
	this->curr_x++;
};

void Position::incy()
{
	this->curr_y++;
};

void Position::setx(int x)
{
	this->curr_x = x;
}

Position _POSITION;
