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
	std::string source_text = Context::file.read_from_file();
	for (int i = 0; i < source_text.size()-1; i++)
	{
		Position::incx();
		switch (source_text[i])
		{
		case 10:
			Position::incy();
			Position::resetx();
		};

		Context::pressed_history.set_pressed(Position::gety(), Position::getx());
		Context::file.save_to_buffer(source_text[i], Position::gety(), Position::getx());
		printw("%c", source_text[i]);
	}
	const auto pressed = Context::pressed_history.get_pressed();
	for (int i = 0; i < pressed.size(); i++)
	{
		Context::dev_log.write_to_file(std::to_string(pressed[i].x).append(" - ").append(std::to_string(pressed[i].y)).append("\n").c_str());
	}

	while (1)
	{
		Position::set_max_coords();

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
