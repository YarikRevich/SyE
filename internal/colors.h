#include <ncurses.h>

#define DEFAULT 1
#define BLUE 2

void init_colors()
{
	start_color();
	init_pair(DEFAULT, COLOR_GREEN, COLOR_BLUE);
	init_pair(BLUE, COLOR_GREEN, COLOR_RED);
	attron(COLOR_PAIR(DEFAULT));
}

void set_color(int color_pair)
{
	attron(COLOR_PAIR(color_pair));
}
