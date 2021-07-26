#include <ncurses.h>
#include <tuple>
#include "position.hpp"

int Coords::curr_y, Coords::curr_x;
int Coords::max_y, Coords::max_x;

void Coords::updateMaxCoords()
{
	getmaxyx(stdscr, Coords::max_y, Coords::max_x);
};

void Coords::updateCurrentCoords()
{
	getyx(stdscr, Coords::curr_y, Coords::curr_x);
};

void Coords::resetX()
{
	Coords::curr_x = 0;
};

void Coords::setX(int x)
{
	Coords::curr_x = x;
};

void Coords::setY(int y){
	Coords::curr_y = y;
};

void Coords::decX()
{
	Coords::curr_x--;
};

void Coords::decY()
{
	Coords::curr_y--;
};

void Coords::incX()
{
	Coords::curr_x++;
};

void Coords::incY()
{
	Coords::curr_y++;
};

bool Position::startOfY, Position::startOfX;

void Position::resetPositionPoints()
{
	Position::startOfX = false;
	Position::startOfY = false;
};


void Position::setStartOfY(bool status)
{
	Position::startOfY = status;
};

bool Position::isStartOfY()
{
	return Position::startOfY;
};

void Position::setStartOfX(bool status)
{
	Position::startOfX = status;
};

bool Position::isStartOfX()
{
	return Position::startOfX;
};
