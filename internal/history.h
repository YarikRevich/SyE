#include <tuple>
#include <vector>

using namespace std;

typedef struct
{
	int y;
	int x;
} cell;

namespace h
{
	vector<cell> _pressed;
	int prev_y, prev_x;

	tuple<int, int> get_prev_yx()
	{
		return {prev_y, prev_x};
	};

	void set_prev_yx(int y, int x)
	{
		prev_y = y;
		prev_x = x;
	};

	void set_pressed(int y, int x)
	{
		_pressed.push_back({y, x});
	};

	void delete_from_pressed(int y, int x)
	{
		vector<cell> n;
		for (int i = 0; i < _pressed.size(); i++)
		{
			if (_pressed[i].x != x && _pressed[i].y != y)
			{
				n.push_back(_pressed[i]);
			};
		}
		_pressed = n;
	};

	int get_new_pointer_pos_x(int y)
	{
		vector<cell> ch;
		for (int i = 0; i < _pressed.size(); i++)
		{
			if (_pressed[i].y == y)
			{
				ch.push_back(_pressed[i]);
			}
		}

		return ch.size();
	};
};
