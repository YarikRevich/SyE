#include "loop.hpp"
#include <iostream>
#include <ncurses.h>
#include <functional>
#include "./../bufs/bufs.hpp"
#include "./../files/log/log.hpp"
#include "./../status/status.hpp"
#include "./../render/render.hpp"
#include "./../files/exec/exec.hpp"
#include "./../states/pool/pool.hpp"
#include "./../files/helper/helper.hpp"
#include "./../colors/insert/insert.hpp"
#include "./../colors/effects/effects.hpp"
#include "./../colors/command/command.hpp"
#include "./../states/common/common.hpp"
#include "./../states/insert/insert.hpp"
#include "./../states/search/search.hpp"
#include "./../states/command/command.hpp"
#include "./../highlighter/highlighter.hpp"
#include "./../term_flags/term_flags.hpp"
#include "./../files/configs/theme_config/theme_config.hpp"
#include "./../files/configs/syntax_config/syntax_config.hpp"

//Middlewares logic

Middleware::Middleware(std::function<void()> middleware)
{
	this->middleware = middleware;
};

void Middleware::use()
{
	this->middleware();
};

MiddlwareExecutor::MiddlwareExecutor(std::vector<Middleware> middlewares)
{
	for (int i = 0; i < middlewares.size(); i++)
	{
		middlewares[i].use();
	};
};

//####### Initialisers

void Stages::Initialisers::init_insert_buf(){
	// _RENDERER.init_render_with_color(_EXEC_FILE->read());
};

void Stages::Initialisers::init_configs()
{
	_SYNTAX_CONFIG.open_and_read();
	_THEME_CONFIG.open_and_read();
};

void Stages::Initialisers::init_term_flags()
{
	TermFlags::check_executive_flag();
	TermFlags::check_dev_flag();
};

void Stages::Initialisers::init_ncurses()
{
	initscr();
	set_escdelay(FALSE);
	noecho();
	scrollok(stdscr, TRUE);
	keypad(stdscr, TRUE);
};

void Stages::Initialisers::init_colors()
{
	start_color();
	auto theme_config_data = _THEME_CONFIG.get();

	_INSERT_COLOR->set(theme_config_data.insert);
};

void Stages::Initialisers::init_signals()
{
	signal(SIGINT, close_all_files);
};

//####### Loop parts

void Stages::LoopParts::process_states()
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

//####### Render

void Stages::LoopParts::Render::do_before_render()
{

	clear(); //Clears terminal screen

	_POSITION.update_curr_coords();

	_HIGHLIGHTER->analiseCode();
};

void Stages::LoopParts::Render::render()
{
	_RENDERER->set_buf(_EFFECTS__BUF)->set_color(_EFFECTS_COLOR->get_current_theme())->render();
	_RENDERER->set_buf(_INSERT__BUF)->set_color(_INSERT_COLOR->get_current_theme())->render();
	_RENDERER->set_buf(_COMMAND__BUF)->set_color(_COMMAND_COLOR->get_current_theme())->render();
};

void Stages::LoopParts::Render::do_after_render()
{
	_LOG_FILE->save();
};

//#######

void Stages::LoopParts::reset_temporary_data()
{
	reset_handled_status();

	_POSITION.resetMovements();

	_INSERT__BUF->resetIgnoreForcibleMove();
	_COMMAND__BUF->resetIgnoreForcibleMove();
};

void Loop::run()
{
	MiddlwareExecutor({
		Middleware(Stages::Initialisers::init_term_flags),
		Middleware(Stages::Initialisers::init_configs),
		Middleware(Stages::Initialisers::init_insert_buf),
		Middleware(Stages::Initialisers::init_ncurses),
		Middleware(Stages::Initialisers::init_colors),
		Middleware(Stages::Initialisers::init_signals),
	});
	// start_color();
	// init_pair(1, COLOR_BLACK, COLOR_BLUE);
	// attron(COLOR_PAIR(1));
	// exit(0);

	while (1)
	{
		MiddlwareExecutor({
			Middleware(Stages::LoopParts::process_states),
			Middleware(Stages::LoopParts::Render::do_before_render),
			Middleware(Stages::LoopParts::Render::render),
			Middleware(Stages::LoopParts::Render::do_after_render),
			Middleware(Stages::LoopParts::reset_temporary_data),
		});
	};
};
