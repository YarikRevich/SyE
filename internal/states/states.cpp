#include "./../position/position.hpp"
#include "./../context/context.hpp"
#include <map>
#include "states.hpp"

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
}

void hnd::CommonHandler::handle(int ch)
{
	switch (ch)
	{
	case 127:
		if (hnd::get_handled_status(BACKSPACE))
		{
			return;
		}
		Context::pressed_history.delete_pressed(Position::gety(), Position::getx() - 1);
		Context::file.delete_from_buffer(Position::gety(), Position::getx() - 1);
		mvdelch(Position::gety(), Position::getx() - 1);
		move(Position::gety(), Position::getx() - 1);
		Position::decx();
	}
};

void hnd::InsertHandler::handle(int ch)
{
	switch (ch)
	{
	case 127:
		return;
	case 10:
	{
		Position::incy();
		Position::resetx();
		move(Position::gety(), Position::getx());
		return;
	}
	case 58:
	{
		Context::prev_history.set_prev_yx(Position::gety(), Position::getx());
		auto [max_y, max_x] = Position::get_max_coords();
		mvaddch(max_y - 1, 0, ch);
		sm::set_state(COMMAND);
		return;
	}
	}

	Context::pressed_history.set_pressed(Position::gety(), Position::getx());
	Context::file.save_to_buffer(ch, Position::gety(), Position::getx());
	printw("%c", ch);
};

void hnd::CommandHandler::handle(int ch)
{
	switch (ch)
	{
	case 10:
	{
		Context::dev_log.write_to_file(Context::command_tools.get_command().c_str());
		Context::command_tools.apply_command(Context::command_tools.get_command());

		auto [prev_y, prev_x] = Context::prev_history.get_prev_yx();
		do
		{
			mvdelch(Position::gety(), Position::getx() - 1);
			Position::decx();
		} while (Position::getx() != 0);
		move(prev_y, prev_x);
		sm::set_state(INSERT);
		Context::command_tools.delete_command();
		return;
	}
	case 127:
	{

		if (Position::getx() - 1 == 0)
		{
			Context::dev_log.write_to_file("BEFORE BACKSPACE\n");
			auto [prev_y, prev_x] = Context::prev_history.get_prev_yx();
			Context::dev_log.write_to_file("BEFORE DELETING SYMBOL\n");
			mvdelch(Position::gety(), Position::getx() - 1);
			Context::dev_log.write_to_file("BEFORE MOVING\n");
			move(prev_y, prev_x);
			Context::dev_log.write_to_file("BEFORE SETTINGS INSERT STATUS\n");
			sm::set_state(INSERT);
			Context::dev_log.write_to_file("BEFORE DELETING COMMAND\n");
			Context::command_tools.delete_command();
			Context::dev_log.write_to_file("BEFORE SETTING STATUS\n");
			set_handled_status(BACKSPACE, true);
			Context::dev_log.write_to_file("AFTER BACKSPACE\n");
		};
		Context::command_tools.pop_symbol_from_command();
		return;
	}
	}
	Context::command_tools.set_command(ch);
	printw("%c", ch);
};

void hnd::HandlerPool::handle(hnd::Handler *h, int ch)
{
	h->handle(ch);
};
