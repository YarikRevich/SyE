#pragma once

#include "../common/common.hpp"
#include "../../../state/state.hpp"
#include "../../../io/helper/helper.hpp"
#include "../../../io/loader/config/config.hpp"
#include "../../../io/loader/theme/theme.hpp"

/**
 * Represents effect responsible for config loader initialization.
*/
class LoaderEffect : public EffectsOperationWithSignal {
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