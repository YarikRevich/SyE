#pragma once

#include "../common/common.hpp"

#include <cstdlib>

/**
 * Represents time widget to be used by widget manager.
*/
class TimeWidget : public WidgetProcessingOperationWithSignal {
public:
    /**
    * @see WidgetOperationWithSignal
    */
    int handleExec() override;

    /**
    * @see WidgetOperationWithSignal
    */
    int handleExit() override;
};