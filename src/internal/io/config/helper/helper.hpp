#pragma once

#include "../loader/loader.hpp"

/**
 * Represents helper used for config operations.
*/
class ConfigHelper {
public:
    /**
     * Checks if given widget is activated.
     *
     * @param value - given widget name to be checked.
     * @return result of the check.
     */
    static bool isWidgetActive(std::string value);
};