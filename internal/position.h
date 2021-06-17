#include <ncurses.h>
#include <tuple>

using namespace std;
class Position{
	private:
		int curr_y, curr_x;	
		int max_y, max_x;
	public:
		Position(){	
			getmaxyx(stdscr, this->max_y, this->max_x);
		};

		tuple<int, int> get_max_coords(){	
			//Returns max coords of the window

			return {this->max_y, this->max_x};
		};	
	
		int getx(){	
			return this->curr_x;
		};

		void resetx(){
			this->curr_x = 0;
		}

		int gety(){	
			return this->curr_y;
		};	
	
		void update_curr_pos(){
			getyx(stdscr, this->curr_y, this->curr_x);
		};

		void decx(){
			--this->curr_x;
		};
		void decy(){
			--this->curr_y;
		};
		void incx(){
			++this->curr_x;
		};
		void incy(){
			++this->curr_y;
		};
};
