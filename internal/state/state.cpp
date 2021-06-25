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

State _STATE;