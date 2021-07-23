#include <tuple>
#include <vector>
#include "history.hpp"

int PreviouslyPressedHistory::y, PreviouslyPressedHistory::x;

void PreviouslyPressedHistory::set(int y, int x){
	PreviouslyPressedHistory::x = x;
	PreviouslyPressedHistory::y = y;
};