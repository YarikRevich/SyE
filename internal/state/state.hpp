#pragma once

//Available states
#define INSERT 0
#define COMMAND 1
#define SEARCH 2

class State
{
private:
    int _CURR_STATE = INSERT;

public:
    void set_state(int state);

    void reset_state();

    int get_state();
};

extern State _STATE;