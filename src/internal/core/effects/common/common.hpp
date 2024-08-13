#pragma once

#include "../../signal/common/common.hpp"

/**
* Represents effect operation interface.
*/
class EffectsOperation {
public:
    /**
     * Handles operation execution.
     *
     * @return result of operation execution.
     */
    virtual int handleExec() = 0;
};

/**
* Represents combination of effect operation and signal operation interfaces.
*/
class EffectsOperationWithSignal : public EffectsOperation, public SignalOperation {};