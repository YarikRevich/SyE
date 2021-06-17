#define INSERT 0
#define COMMAND 1

class StateMachine{
	private:
		int current_state = INSERT;
	public:
		void set_state(int state){
			current_state = state;
		};

		void reset_state(){
			current_state = INSERT;
		};

		int get_state() {
			return current_state; 
		};

};


