#pragma once

#include <map>
#include <vector>
#include "./../../../bufs/bufs.hpp"

namespace CommonStateHelper
{
    extern std::map<int, bool> key_handlers;

    extern std::vector<int> key_exceptions;

    bool isKeyException(int ch);

    void setKeyHandled(int ch);

    bool isKeyHandled(int ch);

    void resetKeysHandled();

    bool isCommonKeyHandler(int ch);
};