#pragma once

#include "../common/common.hpp"
#include "../../../state/state.hpp"
#include "../../../io/helper/helper.hpp"
#include "../../../tools/window/window.hpp"

/**
 * Represents effect responsible for file content initialization.
*/
class ContentEffect : public EffectsOperationWithSignal {
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