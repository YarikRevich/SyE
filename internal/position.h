#include <ncurses.h>
#include <tuple>

using namespace std;

namespace p
{
	//It's a namespace for positioning

	int curr_y, curr_x;
	int max_y, max_x;

	tuple<int, int> get_max_coords()
	{
		return {max_y, max_x};
	};

	int getx()
	{
		return curr_x;
	};

	void resetx()
	{
		curr_x = 0;
	}

	int gety()
	{
		return curr_y;
	};

	void set_max_coords()
	{
		getmaxyx(stdscr, max_y, max_x);
	};

	void update_curr_pos()
	{
		getyx(stdscr, curr_y, curr_x);
	};

	void decx()
	{
		--curr_x;
	};
	void decy()
	{
		--curr_y;
	};
	void incx()
	{
		++curr_x;
	};
	void incy()
	{
		++curr_y;
	};
};
