#pragma once

#include <tuple>
#include <vector>

class PressHistory
{
public:
    int y, x;

    void set(int y, int x);
};

extern PressHistory *PressHistoryStandard;
extern PressHistory *PressHistoryCommand;
extern PressHistory *PressHistoryMaxCoords;