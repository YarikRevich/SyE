#pragma once

#include <string>

/**
 * Represents time widget state holder.
 */
class TimeWidgetState {
public:
    /**
    * Retrieves current time.
    *
    * @return retrieved current time.
    */
    std::string getTime();

    /**
     * Sets current time.
     *
     * @param value - current time to be set.
     */
    void setTime(std::string value);
private:
    /**
     * Represents current time.
    */
    std::string time;
};