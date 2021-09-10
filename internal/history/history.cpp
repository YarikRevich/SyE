#include <tuple>
#include <vector>
#include "history.hpp"

void PressHistory::set(int y, int x)
{
	this->y = y, this->x = x;
};

PressHistory *PressHistoryStandard = new PressHistory;
PressHistory *PressHistoryCommand = new PressHistory;
PressHistory *PressHistoryMaxCoords = new PressHistory;