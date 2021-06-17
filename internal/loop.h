#include <stdio.h>
#include <ncurses.h>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <vector>
#include "state.h"

using namespace std;
void run_loop()
{
	p::set_max_coords();
	while (1)
	{
		s_handler::prepare_handlers();

		int key = getch();
		p::update_curr_pos();
		switch (key)
		{
		case KEY_UP:
			p::decy();
			move(p::gety(), p::getx());
			continue;
		case KEY_DOWN:
			p::incy();
			move(p::gety(), p::getx());
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

		switch (s_machine::get_state())
		{
		case s_machine::INSERT:
			s_handler::handle_insert_state(key);
			break;
		case s_machine::COMMAND:
			s_handler::handle_command_state(key);
		}

		if (!s_handler::getCommonHandledByOthers() && s_handler::handle_common(key))
		{
			continue;
		}
	}
}
