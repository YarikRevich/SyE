#include "loop.hpp"
#include <ncurses.h>
#include "./../bufs/bufs.hpp"
#include "./../files/log/log.hpp"
#include "./../status/status.hpp"
#include "./../render/render.hpp"
#include "./../files/exec/exec.hpp"
#include "./../states/pool/pool.hpp"
#include "./../files/config/config.hpp"
#include "./../states/common/common.hpp"
#include "./../states/insert/insert.hpp"
#include "./../states/search/search.hpp"
#include "./../states/command/command.hpp"
#include "./../highlighter/highlighter.hpp"

void Stages::prepare_run()
{
	_RENDERER.init_render_with_color(_EXEC_FILE->read());
	_CONFIG_FILE->read_config();
};

void Stages::handle_updation()
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
};

void Stages::prepare_for_render()
{

	clear(); //Clears terminal screen

	_POSITION.update_curr_coords();

	_HIGHLIGHTER->analiseCode();
};

void Stages::render()
{
	_RENDERER.render_with_color(_EFFECTS__BUF, COMMAND_THEME);
	//_RENDERER.render_with_main_color(_INSERT__BUF, _COLORS->get_main_color());
	_RENDERER.render_with_color(_COMMAND__BUF, COMMAND_THEME);
};

void Stages::post_render()
{
	_LOG_FILE->save();
};

void Stages::reset_temporary_data()
{
	reset_handled_status();

	_POSITION.resetMovements();

	_INSERT__BUF->resetIgnoreForcibleMove();
	_COMMAND__BUF->resetIgnoreForcibleMove();
};

void Loop::run()
{
	this->prepare_run();

	while (1)
	{
		this->handle_updation();

		this->prepare_for_render();
		this->render();
		this->post_render();

		this->reset_temporary_data();
	};
}

Loop *_LOOP = new Loop;
