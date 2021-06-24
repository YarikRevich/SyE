#include "./../position/position.hpp"
#include "./../context/context.hpp"
#include "./../colors/colors.hpp"
#include <map>
#include "states.hpp"

#ifdef __APPLE__
#define OS_BACKSPACE 127
#elif defined(linux)
#define OS_BACKSPACE 263
#endif

int sm::_CURR_STATE = INSERT;

void sm::set_state(int state)
{
	_CURR_STATE = state;
};

void sm::reset_state()
{
	_CURR_STATE = INSERT;
};

int sm::get_state()
{
	return _CURR_STATE;
};

std::map<int, bool> hnd::handler_status = {
	{BACKSPACE, false},
};

void hnd::set_handled_status(int id, bool status)
{
	handler_status[id] = status;
};

bool hnd::get_handled_status(int id)
{
	return handler_status[id];
};

void hnd::reset_handled_status()
{
	for (auto const &[key, _] : handler_status)
	{
		handler_status[key] = false;
	};
};

void hnd::CommonHandler::handle(int ch)
{
	switch (ch)
	{
	case OS_BACKSPACE:
		if (hnd::get_handled_status(BACKSPACE))
		{
			return;
		}
		Context::pressed_history.delete_pressed(Position::gety(), Position::getx() - 1);
		Context::file.delete_from_buffer(Position::gety(), Position::getx() - 1);
		mvdelch(Position::gety(), Position::getx() - 1);
		wmove(stdscr, Position::gety(), Position::getx() - 1);
		if (Position::getx() == 0)
		{
			Position::decy();
			wmove(stdscr, Position::gety(), Context::pressed_history.get_best_x(Position::gety()));
		}
		else
		{
			Position::decx();
		};
	};
};

void hnd::InsertHandler::handle(int ch)
{

	auto [max_y, max_x] = Position::get_max_coords();

	switch (ch)
	{
	case OS_BACKSPACE:
		return;
	case 10:
	{
		Position::incy();
		Position::resetx();
		break;
	}
	case 58:
	{
		Context::prev_history.set_prev_yx(Position::gety(), Position::getx());
		turn_on_command_theme();

		int i = 0;
		while (i != max_x - 1)
		{
			mvwprintw(stdscr, max_y - 1, i, "%c", 32);
			i++;
		}
		mvwprintw(stdscr, max_y - 1, 0, "%c", ch);
		sm::set_state(COMMAND);
		return;
	}
	}
	if (ch != 10 && ch != 58)
	{
		Context::pressed_history.set_pressed(Position::gety(), Position::getx());
	}
	Context::file.save_to_buffer(ch, Position::gety(), Position::getx());
	if (ch == 10 && Position::gety() == (max_y-1))
	{
		wprintw(stdscr, "\n\n");
		wmove(stdscr, Position::gety()-1, Position::getx());
	}
	else
	{
		wprintw(stdscr, "%c", ch);
	}
};

void hnd::CommandHandler::handle(int ch)
{
	switch (ch)
	{
	case 10:
	{
		Context::command_tools.apply_command(Context::command_tools.get_command());

		auto [prev_y, prev_x] = Context::prev_history.get_prev_yx();
		auto [max_y, max_x] = Position::get_max_coords();
		int i = 0;
		do
		{
			mvdelch(Position::gety(), max_x - i);
			Position::decx();
			i++;
		} while (i != max_x + 1);
		wmove(stdscr, prev_y, prev_x);
		sm::set_state(INSERT);
		turn_off_command_theme();
		Context::command_tools.delete_command();
		return;
	}
	case OS_BACKSPACE:
	{

		if (Position::getx() - 1 == 0)
		{
			auto [prev_y, prev_x] = Context::prev_history.get_prev_yx();
			auto [max_y, max_x] = Position::get_max_coords();
			int i = 0;
			do
			{
				mvdelch(Position::gety(), max_x - i);
				i++;
			} while (i != max_x + 1);
			wmove(stdscr, prev_y, prev_x);
			sm::set_state(INSERT);
			turn_off_command_theme();

			Context::command_tools.delete_command();
			set_handled_status(BACKSPACE, true);
			return;
		};

		auto [max_y, max_x] = Position::get_max_coords();
		int b = 0;
		while (b != max_x - 1)
		{
			mvwprintw(stdscr, max_y - 1, b, "%c", 32);
			b++;
		}
		Context::command_tools.pop_symbol_from_command();
		mvwprintw(stdscr, max_y - 1, 0, ":%s", Context::command_tools.get_command().c_str());
		set_handled_status(BACKSPACE, true);
		return;
	}
	}
	Context::command_tools.set_command(ch);
	wprintw(stdscr, "%c", ch);
};

void hnd::HandlerPool::handle(hnd::Handler *h, int ch)
{
	h->handle(ch);
};
