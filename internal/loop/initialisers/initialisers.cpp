#include "initialisers.hpp"

#include <csignal>
#include <thread>
#include <ncurses.h>
#include "./../../render/render.hpp"
#include "./../../files/exec/exec.hpp"
#include "./../../widgets/time/time.hpp"
#include "./../../files/helper/helper.hpp"
#include "./../../colors/insert/insert.hpp"
#include "./../../term_flags/term_flags.hpp"
#include "./../../highlighter/highlighter.hpp"
#include "./../../files/configs/theme_config/theme_config.hpp"
#include "./../../files/configs/syntax_config/syntax_config.hpp"

void LoopInitialisers::init_insert_buf(){
	_RENDERER->init_render(_EXEC_FILE->read());
};

void LoopInitialisers::init_analiser(){
	_HIGHLIGHTER->analiseCode();
}

void LoopInitialisers::init_insert_buf_render(){
	_RENDERER->set_buf(_INSERT__BUF)->render();
}

void LoopInitialisers::init_configs()
{
	_SYNTAX_CONFIG.open_and_read();
	_THEME_CONFIG.open_and_read();
};

void LoopInitialisers::init_term_flags()
{
	TermFlags::check_executive_flag();
	TermFlags::check_dev_flag();
};

void LoopInitialisers::init_ncurses()
{
	initscr();
	set_escdelay(FALSE);
	noecho();
	scrollok(stdscr, TRUE);
	keypad(stdscr, TRUE);
};

void LoopInitialisers::init_colors()
{
	start_color();
	auto theme_config_data = _THEME_CONFIG.get();

	_INSERT_COLOR->set(theme_config_data.insert);
};

void LoopInitialisers::init_signals()
{
	signal(SIGINT, close_all_files);
};

void LoopInitialisers::init_widgets(){
	std::thread{Time::use}.detach();
};