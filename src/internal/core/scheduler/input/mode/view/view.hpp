#pragma once

#include "../common/common.hpp"
#include "../../../../../state/state.hpp"

#include <cstdlib>

/**
 * Represents view input mode.
 */
class InputView : public InputMode {
    /**
     * @see InputMode
     */
    int getType() override;

    /**
     * @see InputMode
     */
    int handleExec() override;
};