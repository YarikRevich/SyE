#pragma once

#include <map>
#include <vector>
#include "./../../../bufs/bufs.hpp"

namespace CommonStateAutomation
{
    template<class... Buffs>
    void setIgnoreForcibleMoveForAffectedBuffs(Buffs&...);

    void setMoveForCurrentlyUsedStateBuffer(int y, int x);
};

namespace CommonStateHelper
{
    extern std::map<int, bool> key_handlers;

    void setKeyHandled(int ch);

    bool isKeyHandled(int ch);

    void resetKeysHandled();

    bool isCommonKeyHandler(int ch);
};
