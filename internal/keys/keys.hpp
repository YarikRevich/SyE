#pragma once

#ifdef __APPLE__
#define K_BACKSPACE 127
#elif defined(linux)
#define K_BACKSPACE 263
#endif

#define K_COLON 58
#define K_ENTER 10

#include <tuple>
#include <vector>

std::tuple<std::vector<char>, bool> ctrl(int ch);