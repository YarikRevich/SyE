#include <ncurses.h>
#include "states/command/command.hpp"
#include "states/common/common.hpp"
#include "states/insert/insert.hpp"
#include "states/pool/pool.hpp"
#include "states/search/search.hpp"
#include "state/state.hpp"
#include "file/file.hpp"
#include "./render/render.hpp"

using namespace std;
void run_loop()
{
	_RENDERER.init_render(_FILE.read());

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

		_RENDERER.render(_FILE.get());

		wrefresh(stdscr);
	}
}
