#pragma once

#include "../common/common.hpp"
#include "../../../state/state.hpp"
#include "../../../io/helper/helper.hpp"

/**
 * Represents effect responsible for input file initialization.
*/
class InputEffect : public EffectsOperationWithSignal {
public:
    /**
     * @see EffectsOperationWithSignal
     */
    int handleExec() override;

    /**
     * @see EffectsOperationWithSignal
     */
    int handleExit() override;
};