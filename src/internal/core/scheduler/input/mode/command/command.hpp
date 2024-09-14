#pragma once

#include "../common/common.hpp"
#include "../../../../../state/state.hpp"

#include <cstdlib>

/**
 * Represents command input mode.
 */
class InputCommand : public InputMode {
    /**
     * @see InputMode
     */
    int getType() override;

    /**
     * @see InputMode
     */
    int handleExec() override;
};