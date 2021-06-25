#pragma once

#include <vector>
#include <set>

//Available states
#define INSERT 0
#define COMMAND 1
#define SEARCH 2

class State
{
private:
    int _STATE_BEFORE_COMMAND;
    int _CURR_STATE = INSERT;

public:
    void set_state(int state);

    void reset_state();

    int get_state();

    void set_checkpoint_before_command();

    int get_checkpoint_before_command();
};

extern State _STATE;