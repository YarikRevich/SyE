#pragma once

#include "../../../signal/common/common.hpp"

/**
* Represents widget processing operation interface.
*/
class WidgetProcessingOperation {
public:
    /**
     * Handles operation execution.
     *
     * @return result of the operation execution.
     */
    virtual int handleExec() = 0;
};

/**
* Represents combination of widget processing operation and signal operation interfaces.
*/
class WidgetProcessingOperationWithSignal : public WidgetProcessingOperation, public SignalOperation {};