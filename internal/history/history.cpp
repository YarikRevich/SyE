#include <tuple>
#include <vector>
#include "history.hpp"

std::tuple<int, int> PrevHistory::get_prev_yx()
{
	return {prev_y, prev_x};
};

void PrevHistory::set_prev_yx(int y, int x)
{
	prev_y = y;
	prev_x = x;
};

PrevHistory _PREV_HISTORY;

// void PressedHistory::set_pressed(int y, int x)
// {
// 	p_cell *p = new p_cell();
// 	p->y = y;
// 	p->x = x;
// 	pressed.push_back(p);
// };

// std::vector<p_cell *> PressedHistory::get_pressed()
// {
// 	return pressed;
// };

// void PressedHistory::delete_pressed(int y, int x)
// {
// 	std::vector<p_cell *> n;
// 	for (int i = 0; i < pressed.size(); i++)
// 	{
// 		if (!((pressed[i]->x == x) && (pressed[i]->y == y)))
// 		{
// 			n.push_back(pressed[i]);
// 		};
// 	}
// 	pressed = n;
// };

// //Due to the history it choses the best x to move the pointer
// //during the moving up and down
// int PressedHistory::get_best_x(int y)
// {
// 	std::vector<p_cell> ch;
// 	for (int i = 0; i < pressed.size(); i++)
// 	{
// 		if (pressed[i]->y == y)
// 		{
// 			ch.push_back(*pressed[i]);
// 		}
// 	}

// 	return ch.size();
// };

// void PressedHistory::translocation_up()
// {
// 	for (int i = 0; i < pressed.size(); i++)
// 	{
// 		pressed[i]->y++;
// 	}
// };
// void PressedHistory::translocation_down()
// {
// 	for (int i = 0; i < pressed.size(); i++)
// 	{
// 		pressed[i]->y--;
// 	}
// };

// PressedHistory _PRESSED_HISTORY;