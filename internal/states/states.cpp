#include "position.h"
#include "states.hpp"
#include <map>
#include "./../commands/commands.hpp"
#include "./../history/history.hpp"

#define INSERT 0
#define COMMAND 1

//Common handlers ids

#define BACKSPACE 2

namespace sm
{
	int _CURR_STATE = INSERT;

	void set_state(int state)
	{
		_CURR_STATE = state;
	};

	void reset_state()
	{
		_CURR_STATE = INSERT;
	};

	int get_state()
	{
		return _CURR_STATE;
	};
};

namespace hnd
{
	PrevHistory prev_history;
	PressedHistory pressed_history;
	std::map<int, bool> handler_status = {
		{BACKSPACE, false},
	};

	void set_handled_status(int id, bool status)
	{
		handler_status[id] = status;
	};

	bool get_handled_status(int id)
	{
		return handler_status[id];
	};

	class CommonHandler : public Handler
	{
		void handle(int ch)
		{
			switch (ch)
			{
			case 127:
				pressed_history.delete_pressed(p::gety(), p::getx() - 1);
				f::delete_from_buffer(p::gety(), p::getx() - 1);
				mvdelch(p::gety(), p::getx() - 1);
				move(p::gety(), p::getx() - 1);
				p::decx();
			}
		}
	};

	class InsertHandler : public Handler
	{
		void handle(int ch)
		{
			switch (ch)
			{
			case 127:
				return;
			case 10:
			{
				p::incy();
				p::resetx();
				move(p::gety(), p::getx());
				return;
			}
			case 58:
			{
				h::set_prev_yx(p::gety(), p::getx());
				auto [max_y, max_x] = p::get_max_coords();
				mvaddch(max_y - 1, 0, key);
				sm::set_state(COMMAND);
				return;
			}
			}

			pressed_history.set_pressed(p::gety(), p::getx());
			f::save_to_buffer(ch, p::gety(), p::getx());
			printw("%c", ch);
		}
	};

	class CommandHandler : public Handler
	{
		void handle(int ch)
		{
			switch (ch)
			{
			case 10:
			{
				c::apply_command(c::get_command());

				auto [prev_y, prev_x] = prev_history.get_prev_yx();
				do
				{
					mvdelch(p::gety(), p::getx() - 1);
					p::decx();
				} while (p::getx() != 0);
				move(prev_y, prev_x);
				sm::set_state(INSERT);
				c::reset_command();
				return;
			}
			case 127:
			{
				if (p::getx() - 1 == 0)
				{
					auto [prev_y, prev_x] = prev_history.get_prev_yx();
					mvdelch(p::gety(), p::getx() - 1);
					move(prev_y, prev_x);
					sm::set_state(INSERT);
					c::reset_command();
					setCommonHandledByOthers(true);
				};
				c::pop_symbol_from_command();
				return;
			}
			}
			c::set_command(ch);
			printw("%c", ch);
		}
	};

	class HandlerPool
	{
		void handle(Handler h, int ch)
		{
			h.handle(ch);
		};
	};
};
