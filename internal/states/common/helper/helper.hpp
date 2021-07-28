#pragma once

#include <map>
#include <vector>
#include "./../../../bufs/bufs.hpp"

namespace CommonStateHelper
{
    extern std::map<int, bool> key_handlers;

    void setKeyHandled(int ch);

    bool isKeyHandled(int ch);

    void resetKeysHandled();

    bool isCommonKeyHandler(int ch);
};