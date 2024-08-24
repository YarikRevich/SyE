#include "./entry.hpp"

std::string EntryState::getInputFile() {
    return this->inputFile;
}

void EntryState::setInputFile(std::string value) {
    this->inputFile = value;
}

std::string EntryState::getConfigRoot() {
    return this->configRoot;
}

void EntryState::setConfigRoot(std::string value) {
    this->configRoot = value;
}

std::string EntryState::getInputFileExtension() {
    return this->inputFileExtension;
}

void EntryState::setInputFileExtension(std::string value) {
    this->inputFileExtension = value;
}
