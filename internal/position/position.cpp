#include <ncurses.h>
#include <tuple>
#include "position.hpp"
#include "../bufs/bufs.hpp"
#include "../colors/insert/insert.hpp"
#include "../render/render.hpp"
#include "../history/history.hpp"
#include "../position/position.hpp"
#include "win_resizer/win_resizer.hpp"

int Coords::curr_y, Coords::curr_x;
int Coords::max_y, Coords::max_x;

void Coords::updateMaxCoords()
{

	PressHistoryMaxCoords->set(Coords::max_y, Coords::max_x);
	getmaxyx(stdscr, Coords::max_y, Coords::max_x);

	if (_WIN_RESIZER->areMaxCoordsChanged())
	{
		_WIN_RESIZER->resizeWin();
	}

	// if (Coords::areMaxCoordsChanged())
	// {
	// 	clear();
	// 	_RENDERER->set_buf(_INSERT__BUF)->set_color(_INSERT_COLOR->get_current_theme())->render();
	// }
};

void Coords::updateCurrentCoords()
{
	PressHistoryStandard->set(Coords::curr_y, Coords::curr_x);
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

void Coords::setY(int y)
{
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

void Deleters::sequencial_delch()
{
	auto &&buf = _INSERT__BUF->getBufferIterator();
	if (!((PressHistoryStandard->x == 0 && Coords::curr_y == 0) && (!buf.empty() && buf[0]->symbol == 0)))
	{
		mvdelch(Coords::curr_y, Coords::curr_x);
	}
	wmove(stdscr, Coords::curr_y, Coords::curr_x);
	wrefresh(stdscr);
};

void Deleters::carriage_delch()
{
	mvdelch(Coords::curr_y, 0);
	wrefresh(stdscr);
};

void Deleters::last_in_row_delch()
{
	mvdelch(Coords::curr_y, _INSERT__BUF->getLastXInRow(Coords::curr_y));
	wrefresh(stdscr);
};

void Deleters::hyphination_last_in_row_delch()
{
	// mvdelch(Coords::curr_y, _INSERT__BUF->getLastXInRow(Coords::curr_y));
	mvdelch(Coords::curr_y, _INSERT__BUF->getLastXInRow(Coords::curr_y) - 1);
	wrefresh(stdscr);
};

void Deleters::shiftable_delch(){};

// void coords_delch()
// {
// 	mvdelch(Coords::curr_y, Coords::curr_x - 1);
// 	Coords::decX();
// 	wmove(stdscr, Coords::curr_y, Coords::curr_x);
// };
