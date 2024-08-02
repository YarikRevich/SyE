#pragma once

#include <string>
#include <fstream>

/**
 * Represents file swap manager.
*/
class SwapManager {
public:
    /**
     * Creates new swap file for the file at the given path.
     * 
     * @param file - given file path.
    */
    static void spawn(std::string file);
private:
    /**
     * Represents spawned swap file used as content buffer.
    */
    static std::ofstream swapFile;

    /**
     * Represents previously defined output file for end file.
    */
    static std::string outputFile;
};