#include "loop.hpp"

#include "./helper/helper.hpp"
#include "./processors/processors.hpp"
#include "./initialisers/initialisers.hpp"

void Loop::run()
{
	MiddlwareExecutor({
		Middleware(LoopInitialisers::init_term_flags),
		Middleware(LoopInitialisers::init_configs),
		Middleware(LoopInitialisers::init_ncurses),
		Middleware(LoopInitialisers::init_colors),
		Middleware(LoopInitialisers::init_insert_buf),
		Middleware(LoopInitialisers::init_signals),
	});

	for (;;)
	{
		MiddlwareExecutor({
			Middleware(LoopProcessors::update_coords),
			Middleware(LoopProcessors::process_states),
			Middleware(LoopProcessors::clean_screen),
			Middleware(LoopProcessors::analise_syntax),
			Middleware(LoopProcessors::render),
			Middleware(LoopProcessors::save_debug_files),
			Middleware(LoopProcessors::reset_temp_vals),
		});
	};
};
