#pragma once

#include "../common/common.hpp"
#include "../../../../../state/state.hpp"

#include <cstdlib>

/**
 * Represents insert input mode.
 */
class InputInsert : public InputMode {
    /**
     * @see InputMode
     */
    int getType() override;

    /**
     * @see InputMode
     */
    int handleExec() override;
};