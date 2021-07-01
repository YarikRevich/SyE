#include <ncurses.h>
#include "status/status.hpp"
#include "files/exec/exec.hpp"
#include "files/log/log.hpp"
#include "bufs/bufs.hpp"
#include "./render/render.hpp"
#include "states/pool/pool.hpp"
#include "states/common/common.hpp"
#include "states/insert/insert.hpp"
#include "states/search/search.hpp"
#include "states/command/command.hpp"

void run_loop()
{
	_RENDERER.init_render(_EXEC_FILE.read());

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
		reset_handled_status();

		clear();
		_RENDERER.render(_EFFECTS__BUF.get());
		_RENDERER.render(_INSERT__BUF.get());
		_RENDERER.render(_COMMAND__BUF.get());
		_LOG_FILE.save();
	}
}
