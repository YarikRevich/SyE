#pragma once

#include <tuple>
#include <vector>

#ifdef __APPLE__
#define K_BACKSPACE 127
#elif defined(__linux__)
#define K_BACKSPACE 263
#endif

#define K_COLON 58
#define K_ENTER 10
#define K_TAB 9


std::tuple<std::vector<char>, bool> ctrl(int ch);