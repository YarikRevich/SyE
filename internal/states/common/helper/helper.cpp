#include <any>
#include <vector>
#include <ncurses.h>
#include "helper.hpp"
#include "./../../../keys/keys.hpp"
#include "./../../../editor_status/editor_status.hpp"

std::map<int, bool> CommonStateHelper::key_handlers = {
    {K_BACKSPACE, false},
    {K_COLON, false},
    {KEY_UP, false},
    {KEY_DOWN, false},
    {KEY_LEFT, false},
    {KEY_RIGHT, false},
};

void CommonStateHelper::setKeyHandled(int ch)
{
    CommonStateHelper::key_handlers[ch] = true;
};

bool CommonStateHelper::isKeyHandled(int ch)
{
    if (CommonStateHelper::key_handlers.count(ch)){
        return CommonStateHelper::key_handlers[ch];
    };
    return false;
};

void CommonStateHelper::resetKeysHandled()
{
    for (const auto &key : CommonStateHelper::key_handlers)
    {
        CommonStateHelper::key_handlers[key.first] = false;
    };
};

bool CommonStateHelper::isCommonKeyHandler(int ch)
{
    return CommonStateHelper::key_handlers.count(ch);
};
