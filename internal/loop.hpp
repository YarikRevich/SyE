#include <stdio.h>
#include <ncurses.h>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <vector>
#include "position/position.hpp"
#include "states/states.hpp"

using namespace std;
void run_loop()
{
	std::string source_text = Context::file.read_from_file();
	if (!source_text.empty())
	{
		for (int i = 0; i < source_text.size() - 1; i++)
		{
			switch (source_text[i])
			{
			case 10:
				Position::incy();
				Position::resetx();
				Context::file.save_to_buffer(source_text[i], Position::gety(), Position::getx());
				printw("%c", source_text[i]);
				continue;
			};

			Context::pressed_history.set_pressed(Position::gety(), Position::getx());
			Context::file.save_to_buffer(source_text[i], Position::gety(), Position::getx());
			Position::incx();
			printw("%c", source_text[i]);
		};
	};

	while (1)
	{
		Position::set_max_coords();

		int ch = getch();
		Position::update_curr_pos();

		switch (ch)
		{
		case KEY_UP:
		{
			if (Position::gety() == 0)
			{
				beep();
				continue;
			};
			Position::decy();
			move(Position::gety(), Context::pressed_history.get_best_x(Position::gety()));
			continue;
		}
		case KEY_DOWN:
		{
			auto [max_y, _] = Position::get_max_coords();
			if (Position::gety() == (max_y - 1))
			{
				beep();
				continue;
			};
			Position::incy();
			move(Position::gety(), Context::pressed_history.get_best_x(Position::gety()));
			continue;
		}
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

		//Context::dev_log.write_to_file_str(std::to_string(Context::file.));

		hnd::reset_handled_status();
	}
}
