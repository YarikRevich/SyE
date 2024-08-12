#pragma once

#include "../common/common.hpp"
#include "../../../state/state.hpp"

#include "ncurses.h"
#include <iostream>

/**
 * Represents effect responsible for terminal window initialization.
*/
class WindowEffect : public EffectsOperationWithSignal {
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