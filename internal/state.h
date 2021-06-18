#include "position.h"
#include "history.h"
#include "commands.h"

namespace s_machine
{
	const int INSERT = 0;
	const int COMMAND = 1;

	int CURR_STATE = INSERT;

	void set_state(int state)
	{
		CURR_STATE = state;
	};

	void reset_state()
	{
		CURR_STATE = INSERT;
	};

	int get_state()
	{
		return CURR_STATE;
	};
};

namespace s_handler
{
	bool _isCommonHandledByOthers;
	void setCommonHandledByOthers(bool s)
	{
		_isCommonHandledByOthers = s;
	}

	bool getCommonHandledByOthers()
	{
		return _isCommonHandledByOthers;
	}

	void prepare_handlers()
	{
		setCommonHandledByOthers(false);
	};

	bool handle_common(int key)
	{
		switch (key)
		{
		case 127:
			h::delete_from_pressed(p::gety(), p::getx() - 1);
			mvdelch(p::gety(), p::getx() - 1);
			move(p::gety(), p::getx() - 1);
			p::decx();
			return true;
		}
		return false;
	};

	void handle_insert_state(int key)
	{
		switch (key)
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
			s_machine::set_state(s_machine::COMMAND);
			return;
		}
		}

		h::set_pressed(p::gety(), p::getx());
		printw("%c", key);
	}

	void handle_command_state(int key)
	{
		switch (key)
		{
		case 10:
		{
			c::apply_command(c::get_command());

			auto [prev_y, prev_x] = h::get_prev_yx();
			do
			{
				mvdelch(p::gety(), p::getx() - 1);
				p::decx();
			} while (p::getx() != 0);
			move(prev_y, prev_x);
			s_machine::set_state(s_machine::INSERT);
			c::reset_command();
			return;
		}
		case 127:
		{
			if (p::getx() - 1 == 0)
			{
				auto [prev_y, prev_x] = h::get_prev_yx();
				mvdelch(p::gety(), p::getx() - 1);
				move(prev_y, prev_x);
				s_machine::set_state(s_machine::INSERT);
				c::reset_command();
				setCommonHandledByOthers(true);
			};
			c::pop_symbol_from_command();
			return;
		}
		}
		c::set_command(key);
		printw("%c", key);
	}
};
