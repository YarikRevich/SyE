#include <stdio.h>
#include <ncurses.h>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <vector>


using namespace std;

void run_loop(){
	int prev_x, prev_y;
	int max_x, max_y;
	getmaxyx(stdscr, max_y, max_x);
	while(1){
		getyx(stdscr, prev_y, prev_x);
		int key = getch();
		switch(key){
			case KEY_UP:
				--prev_y;
				move(prev_y, prev_x);
				continue;
			case KEY_DOWN:
				++prev_y;            
				move(prev_y, prev_x);		
				continue;
			case 127:
				mvdelch(prev_y, prev_x-1);
				move(prev_y, prev_x-1);
				--prev_x;
				continue;
			case 10:
				++prev_y;
				prev_x = 0;
				move(prev_y, prev_x);
				continue;
			case 58:
				mvdelch(prev_y, prev_x);
				mvaddch(max_y-1, 0, key);
		}
		printw("%c", key);
	}
}
