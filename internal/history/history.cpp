#include <tuple>
#include <vector>
#include "history.hpp"

int PreviouslyPressedHistory::y, PreviouslyPressedHistory::x;

void PreviouslyPressedHistory::set(int y, int x){
	PreviouslyPressedHistory::x = x;
	PreviouslyPressedHistory::y = y;
};

int PreviousMaxCoords::max_y, PreviousMaxCoords::max_x;

void PreviousMaxCoords::set(int max_y, int max_x){
	PreviousMaxCoords::max_y = max_y;
	PreviousMaxCoords::max_x = max_x;
};