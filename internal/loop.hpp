#include <stdio.h>
#include <ncurses.h>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <vector>
#include "states/command/command.hpp"
#include "states/common/common.hpp"
#include "states/insert/insert.hpp"
#include "states/pool/pool.hpp"
#include "state/state.hpp"
#include "file/file.hpp"
#include "history/history.hpp"
#include "position/position.hpp"

using namespace std;
void run_loop()
{
	auto [curr_y, curr_x] = _POSITION.get_curr_coords();

	std::string source_text = _FILE.read_from_file();
	if (!source_text.empty())
	{
		for (int i = 0; i < source_text.size() - 1; i++)
		{
			switch (source_text[i])
			{
			case 10:
				_POSITION.incy();
				_POSITION.resetx();
				break;
			default:
				_PRESSED_HISTORY.set_pressed(curr_y, curr_x);
				_POSITION.incx();
			};
			_FILE.save_to_buffer(source_text[i], curr_y, curr_x);
			wprintw(stdscr, "%c", source_text[i]);
		};
	};

	while (1)
	{
		int ch = getch();

		auto [max_y, max_x] = _POSITION.get_max_coords();
		auto [curr_y, curr_x] = _POSITION.get_curr_coords();

		switch (ch)
		{
		case KEY_UP:
		{
			if (curr_y == 0)
			{
				beep();
				continue;
			};
			_POSITION.decy();
			wmove(stdscr, curr_y, _PRESSED_HISTORY.get_best_x(curr_y));
			continue;
		}
		case KEY_DOWN:
		{
			if (curr_y == (max_y - 1))
			{
				beep();
				continue;
			};
			_POSITION.incy();
			wmove(stdscr, curr_y, _PRESSED_HISTORY.get_best_x(curr_y));
			continue;
		}
		case KEY_LEFT:
			_POSITION.decx();
			wmove(stdscr, curr_y, curr_x);
			continue;
		case KEY_RIGHT:
			_POSITION.incx();
			wmove(stdscr, curr_y, curr_x);
			continue;
		}

		HandlerPool handler_pool;
		switch (_STATE.get_state())
		{
		case INSERT:
			handler_pool.handle(new InsertHandler, ch);
			break;
		case COMMAND:
			handler_pool.handle(new CommandHandler, ch);
		}
		handler_pool.handle(new CommonHandler, ch);

		wrefresh(stdscr);
	}
}
