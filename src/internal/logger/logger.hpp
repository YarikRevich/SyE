#pragma once

#include <string>
#include <iostream>
#include <sstream>

/**
 * Represents common logger for the application(besides the ones in external libs).
*/
class Logger {
public:
    /**
     * Checks if latest final logger message exist.
     *
     * @return result of logger final message existence check.
    */
    static bool isErrorExist();

    /**
     * Retrieves latest final logger message.
     *
     * @return latest final logger message.
    */
    static std::string getError();

    /**
     * Sets latest final logger message.
     *
     * @param message - latest final logger message.
    */
    static void setError(std::string message);

    /**
     * Sets logger warning message to be emitted immediately.
     * 
     * @param message - given warning message to be emitted.
    */
    static void invokeWarning(std::string message);

    /**
     * Sets logger info message to be emitted immediately.
     * 
     * @param message - given info message to be emitted.
    */
    static void invokeInfo(std::string message);
private:
    /**
     * Represents saved error message.
     */
    static std::string message;
};