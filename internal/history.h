#include <tuple>

using namespace std;

class History{
	private:
		int prev_y, prev_x; 
	public:
		tuple<int, int> get_prev_yx(){
			return {this->prev_y, this->prev_x};
		}; 

		void set_prev_yx(int y, int x){
			this->prev_y = y;
			this->prev_x = x;
		};
};
