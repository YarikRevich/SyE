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
#include "states/search/search.hpp"
#include "state/state.hpp"
#include "file/file.hpp"
#include "history/history.hpp"
#include "position/position.hpp"
#include "log/dev/dev.hpp"

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
				_PRESSED_HISTORY.set_pressed(*curr_y, *curr_x);
				_POSITION.incx();
			};
			_FILE.save_to_buffer(source_text[i], *curr_y, *curr_x);
			wprintw(stdscr, "%c", source_text[i]);
		};
	};

	while (1)
	{
		int ch = getch();

		HandlerPool handler_pool;
		switch (_STATE.get_state())
		{
		case INSERT:
			handler_pool.handle(new InsertHandler, ch);
			break;
		case COMMAND:
			handler_pool.handle(new CommandHandler, ch);
			break;
		case SEARCH:
			handler_pool.handle(new SearchHandler, ch);
		}
		handler_pool.handle(new CommonHandler, ch);

		wrefresh(stdscr);
	}
}
