#pragma once

#include "../common/common.hpp"
#include "../../../state/state.hpp"
#include "../../../io/helper/helper.hpp"

#include <iostream>

#ifdef __APPLE__
#include <filesystem>
namespace fs = std::filesystem;
#elif defined(__linux__)
#include <experimental/filesystem>
namespace fs = std::experimental::filesystem;
#endif

/**
 * Represents effect responsible for swap initialization.
*/
class SwapEffect : public EffectsOperationWithSignal {
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