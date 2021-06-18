#include <stdio.h>
#include <ncurses.h>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <vector>
#include "states/states.hpp"

using namespace std;
void run_loop()
{
	p::set_max_coords();
	while (1)
	{
		int ch = getch();
		p::update_curr_pos();

		switch (ch)
		{
		case KEY_UP:

			p::decy();
			move(p::gety(), h::get_new_pointer_pos_x(p::gety()));
			continue;
		case KEY_DOWN:
			p::incy();
			move(p::gety(), h::get_new_pointer_pos_x(p::gety()));
			continue;
		case KEY_LEFT:
			p::decx();
			move(p::gety(), p::getx());
			continue;
		case KEY_RIGHT:
			p::incx();
			move(p::gety(), p::getx());
			continue;
		}

		hnd::HandlerPool handler_pool;
		switch (s_machine::get_state())
		{
		case s_machine::INSERT:
			handler_pool.handle(new hnd::InsertHandler<>, ch)
			break;
		case s_machine::COMMAND:
			handler_pool.handle(new hnd::CommandHandler<>, ch)
		}

		if (!s_handler::getCommonHandledByOthers() && s_handler::handle_common(ch))
		{
			continue;
		}
	}
}
