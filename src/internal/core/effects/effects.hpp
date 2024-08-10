#pragma once

#include "../../tools/spinner/spinner.hpp"

#include <iostream>

/**
 * Represents effects entrypoint used during.
*/
class Effects {
public:
    /**
     * Performs processing of all the effects.
     *
     * @return result of the effects execution.
     */
    static int process();
};