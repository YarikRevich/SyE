#pragma once

#include <string>

/**
 * Represents entry state holder.
 */
class EntryState {
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

    /**
     * Retrieves config root path.
     *
     * @return retrieved config root path.
     */
    std::string getConfigRoot();

    /**
     * Sets config root path.
     *
     * @param value - config root path.
     */
    void setConfigRoot(std::string value);

    /**
     * Retrieves input file extension.
     *
     * @return retrieved input file extension.
     */
    std::string getInputFileExtension();

    /**
     * Sets input file extension.
     *
     * @param value - input file extension.
     */
    void setInputFileExtension(std::string value);
private:
    /**
     * Represents input file path.
     */
    std::string inputFile;

    /**
     * Represents config root path.
     */
    std::string configRoot;

    /**
     * Represents input file extension.
     */
    std::string inputFileExtension;
};