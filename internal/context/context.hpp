#pragma once

#include "./../history/history.hpp"
#include "./../files/files.hpp"
#include "./../commands/commands.hpp"

namespace Context
{
    extern PrevHistory prev_history;
    extern PressedHistory pressed_history;
    extern File file;
    extern CommandTools command_tools;
};
