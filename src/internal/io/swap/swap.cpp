#include "swap.hpp"

std::string SwapManager::outputFile = "";

void SwapManager::spawn(std::string file) {
    SwapManager::outputFile = file;
}