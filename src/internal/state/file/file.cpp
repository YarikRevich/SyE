#include "./file.hpp"

std::string FileState::getInputFile() {
    return inputFile;
}

void FileState::setInputFile(std::string value) {
    this->inputFile = value;
}
