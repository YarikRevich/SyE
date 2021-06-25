#include "./../position/position.hpp"
#include "./../colors/colors.hpp"
#include <map>
#include "state.hpp"

void State::set_state(int state)
{
    _CURR_STATE = state;
};

void State::reset_state()
{
    _CURR_STATE = INSERT;
};

int State::get_state()
{
    return _CURR_STATE;
};

void State::set_checkpoint_before_command()
{
    _STATE_BEFORE_COMMAND = State::get_state();
};

int State::get_checkpoint_before_command()
{
    return _STATE_BEFORE_COMMAND;
}

State _STATE;