#pragma once

#include <map>
#include <vector>
#include "./../../../bufs/bufs.hpp"

namespace CommonStateAutomation
{
    template<typename... Args>
    void setIgnoreForcibleMoveForAffectedBuffs(Args...);

    void setMoveForCurrentlyUsedStateBuffer(int y, int x);
};

template <typename... Args>
void CommonStateAutomation::setIgnoreForcibleMoveForAffectedBuffs(Args...args)
{
    (args->setIgnoreForcibleMove(true), ...);
};

namespace CommonStateHelper
{
    extern std::map<int, bool> key_handlers;

    void setKeyHandled(int ch);

    bool isKeyHandled(int ch);

    void resetKeysHandled();

    bool isCommonKeyHandler(int ch);
};