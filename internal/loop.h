#include <stdio.h>
#include <ncurses.h>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <vector>
#include "position/position.hpp"
#include "states/states.hpp"
#include "context/context.hpp"

using namespace std;
void run_loop()
{

	Position::set_max_coords();
	while (1)
	{
		int ch = getch();
		Position::update_curr_pos();

		switch (ch)
		{
		case KEY_UP:
			Position::decy();
			move(Position::gety(), Context::pressed_history.get_best_x(Position::gety()));
			continue;
		case KEY_DOWN:
			Position::incy();
			move(Position::gety(), Context::pressed_history.get_best_x(Position::gety()));
			continue;
		case KEY_LEFT:
			Position::decx();
			move(Position::gety(), Position::getx());
			continue;
		case KEY_RIGHT:
			Position::incx();
			move(Position::gety(), Position::getx());
			continue;
		}

		hnd::HandlerPool handler_pool;
		switch (sm::get_state())
		{
		case INSERT:
			handler_pool.handle(new hnd::InsertHandler, ch);
			break;
		case COMMAND:
			handler_pool.handle(new hnd::CommandHandler, ch);
		}

		handler_pool.handle(new hnd::CommonHandler, ch);

		hnd::reset_handled_status();
	}
}
