#pragma once

#include <string>

/**
 * Represents file state holder.
 */
class FileState {
public:
    /**
     * Retrieves input file path.
     *
     * @return retrieved input file path.
     */
    std::string getInputFile();

    /**
     * Sets input file path.
     *
     * @param value - input file path.
     */
    void setInputFile(std::string value);
private:
    /**
     * Represents input file path.
     */
    std::string inputFile;
};