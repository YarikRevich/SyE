#include <stdio.h>
#include <ncurses.h>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <vector>
#include "state.h"
#include "position.h"
#include "history.h"


using namespace std;

void run_loop(){
	Position position;
	History history;
	StateMachine state;
	auto [max_y, max_x] = position.get_max_coords(); 

	while(1){
		position.update_curr_pos();
		int key = getch();
		switch(key){
			case KEY_UP:
				position.decy();
				move(position.gety(), position.getx());
				continue;
			case KEY_DOWN:
				position.incy();            
				move(position.gety(), position.getx());		
				continue;
			case KEY_LEFT:
				position.decx();
				move(position.gety(), position.getx());
				continue;
			case KEY_RIGHT:
				position.incx();
				move(position.gety(), position.getx());
				continue;
			case 127:
				if (state.get_state() == COMMAND && position.getx()-1 == 0){
					state.set_state(INSERT);
					auto [prev_y, prev_x] = history.get_prev_yx();
					mvdelch(position.gety(), position.getx()-1);
					move(prev_y, prev_x);
					continue;
				};	
				mvdelch(position.gety(), position.getx()-1);
				move(position.gety(), position.getx()-1);
				position.decx();
				continue;
			case 10:
				position.incy();
				position.resetx();
				move(position.gety(), position.getx());
				continue;
			case 58:
				if (state.get_state() != COMMAND){
					history.set_prev_yx(position.gety(), position.getx());
					mvaddch(max_y-1, 0, key);
					state.set_state(COMMAND);
				}
				continue;
		}
		printw("%c", key);
	}
}
