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
		Middleware(LoopProcessors::update_coords),
		Middleware(LoopInitialisers::init_insert_buf),
		Middleware(LoopInitialisers::init_analiser),
		Middleware(LoopInitialisers::init_insert_buf_render),
		Middleware(LoopInitialisers::init_signals),
		Middleware(LoopInitialisers::init_widgets),
	});

	for (;;)
	{
		MiddlwareExecutor({
			Middleware(LoopProcessors::update_coords),
			Middleware(LoopProcessors::analise_syntax),
			Middleware(LoopProcessors::process_states),
			Middleware(LoopProcessors::render),
			Middleware(LoopProcessors::save_debug_files),
			Middleware(LoopProcessors::reset_temp_vals),
		});
	};
};
