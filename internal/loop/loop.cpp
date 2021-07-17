#include "loop.hpp"
#include <ncurses.h>
#include <functional>
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

//Middlewares logic

Middleware::Middleware(std::function<void()> middleware){
	this->middleware = middleware;
};

void Middleware::use(){
	this->middleware();
};

MiddlwareExecutor::MiddlwareExecutor(std::vector<Middleware> middlewares){
	for (int i = 0; i < middlewares.size(); i++){
		middlewares[i].use();
	};
};


void Stages::init_insert_buf()
{
	_RENDERER.init_render_with_color(_EXEC_FILE->read());
};

void Stages::init_configs()
{
	_CONFIG_FILE->read_config();
	_
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
	_RENDERER.render(_EFFECTS__BUF);
	_RENDERER.render(_INSERT__BUF);
	//_RENDERER.render_with_main_color(_INSERT__BUF, _COLORS->get_main_color());
	_RENDERER.render(_COMMAND__BUF);
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
	MiddlwareExecutor({
		Middleware(std::bind(&Loop::init_insert_buf, this)),
		Middleware(std::bind(&Loop::init_configs, this)),
	});

	while (1)
	{
		MiddlwareExecutor({
			Middleware(std::bind(&Loop::handle_updation, this)),
			Middleware(std::bind(&Loop::prepare_for_render, this)),
			Middleware(std::bind(&Loop::render, this)),
			Middleware(std::bind(&Loop::post_render, this)),
			Middleware(std::bind(&Loop::reset_temporary_data, this)),
		});
	};
}

Loop *_LOOP = new Loop;
