#pragma once

#include "../../../core/scheduler/operations/input/input.hpp"
#include "../../../core/scheduler/operations/render/render.hpp"
#include "../../../signal/signal.hpp"
#include "../../../core/scheduler/scheduler.hpp"

#include <iostream>

/**
 * Represents effect responsible for initialization of all the components.
*/
class Init {
public:
    /**
     * Performs processing of the effect.
     *
     * @return result of the initialization effect execution.
     */
    static int process();
};