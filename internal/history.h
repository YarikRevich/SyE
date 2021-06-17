#include <tuple>

using namespace std;

namespace h
{
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
};
