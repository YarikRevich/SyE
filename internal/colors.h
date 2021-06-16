#include <ncurses.h>

#define DEFAULT 1
#define BLUE 2

void init_colors(){
	start_color();
	init_pairs(DEFAULT, COLOR_GREEN, COLOR_BLUE);
	init_pairs(BLUE, COLOR_GREEN, COLOR_RED);
}

void set_color(int color_pair){
	attron(COLOR_PAIR(color_pair));
}
