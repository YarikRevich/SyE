#include <tuple>
#include <vector>
#include "history.hpp"
#include "./../context/context.hpp"

std::tuple<int, int> PrevHistory::get_prev_yx()
{
	return {prev_y, prev_x};
};

void PrevHistory::set_prev_yx(int y, int x)
{
	prev_y = y;
	prev_x = x;
};

void PressedHistory::set_pressed(int y, int x)
{
	pressed.push_back({y, x});
};

std::vector<p_cell> PressedHistory::get_pressed()
{
	return pressed;
};

void PressedHistory::delete_pressed(int y, int x)
{
	std::vector<p_cell> n;
	for (int i = 0; i < pressed.size(); i++)
	{
		if (!((pressed[i].x == x) && (pressed[i].y == y)))
		{
			n.push_back(pressed[i]);
		};
	}
	pressed = n;
};

//Due to the history it choses the best x to move the pointer
//during the moving up and down
int PressedHistory::get_best_x(int y)
{
	std::vector<p_cell> ch;
	for (int i = 0; i < pressed.size(); i++)
	{
		if (pressed[i].y == y)
		{
			ch.push_back(pressed[i]);
		}
	}
	Context::dev_log.write_to_file(std::to_string(ch.size()).append("\n").c_str());

	return ch.size();
};