//Available states
#define INSERT 0
#define COMMAND 1

extern int _CURR_STATE;

void set_state(int state);

void reset_state();

int get_state();