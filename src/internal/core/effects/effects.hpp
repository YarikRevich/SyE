#pragma once

#include "common/common.hpp"
#include "../signal/common/common.hpp"
#include "../../tools/spinner/spinner.hpp"

#include <iostream>

/**
 * Represents effects manager.
*/
class Effects : public SignalOperation {
public:
    /**
     * Performs effects initialization.
     */
    Effects();

    /**
     * Performs processing of all the effects.
     *
     * @return result of the effects execution.
     */
    int process();

    /**
     * @see SignalOperation
    */
    int handleExit() override;
private:
    /**
     * Represents collection of registered callbacks.
    */
    std::vector<EffectsOperationWithSignal*> callbacks;
};