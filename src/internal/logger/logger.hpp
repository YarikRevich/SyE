#pragma once

#include <string>
#include <iostream>

/**
 * Represents common logger for the application(besides the ones in external libs).
*/
class Logger {
public:
    /**
     * Checks if latest final logger message exist.
     * @return result of logger final message existance check.
    */
    static bool IsErrorExist();

    /**
     * Retrieves latest final logger message.
     * @return latest final logger message.
    */
    static std::string GetError();

    /**
     * Sets latest final logger message.
     * @param message - latest final logger message.
    */
    static void SetError(std::string message);

    /**
     * Sets logger warning message to be emitted immediately.
     * 
     * @param message - given warning message to be emitted.
    */
    static void InvokeWarning(std::string message);
private:
    static std::string message;
};