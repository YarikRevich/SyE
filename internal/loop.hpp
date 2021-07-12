#include <ncurses.h>
#include "bufs/bufs.hpp"
#include "files/log/log.hpp"
#include "status/status.hpp"
#include "./render/render.hpp"
#include "files/exec/exec.hpp"
#include "states/pool/pool.hpp"
#include "files/config/config.hpp"
#include "states/common/common.hpp"
#include "states/insert/insert.hpp"
#include "states/search/search.hpp"
#include "states/command/command.hpp"
#include "highlighter/highlighter.hpp"

void run_loop()
{
	_RENDERER.init_render(_EXEC_FILE->read());
	_CONFIG_FILE->read_config();
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

		if (!is_common_handled(ch))
		{
			handler_pool.handle(new CommonHandler, ch);
		}

		clear();

		_POSITION.update_curr_coords();

		_HIGHLIGHTER->analiseCode();

		_RENDERER.render_with_color(_EFFECTS__BUF, COMMAND_THEME);
		_RENDERER.render(_INSERT__BUF);
		_RENDERER.render_with_color(_COMMAND__BUF, COMMAND_THEME);
		_LOG_FILE->save();

		reset_handled_status();

		_POSITION.resetMovements();

		_INSERT__BUF->resetIgnoreForcibleMove();
		_COMMAND__BUF->resetIgnoreForcibleMove();
	}
}
