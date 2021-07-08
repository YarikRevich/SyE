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
	getsyx(curr_y, curr_x);
	return {&curr_y, &curr_x};
};

void Position::update_curr_coords()
{
	getsyx(curr_y, curr_x);
};

void PositionMove::resetMovements(){
	this->startOfX = false;
	this->startOfY = false;
};

void PositionMove::setStartOfY(bool status)
{
	this->startOfY = status;
};

bool PositionMove::isStartOfY()
{
	return this->startOfY;
};

void PositionMove::setStartOfX(bool status)
{
	this->startOfX = status;
};

bool PositionMove::isStartOfX()
{
	return this->startOfX;
};

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
