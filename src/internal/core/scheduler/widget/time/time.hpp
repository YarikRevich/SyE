#pragma once

#include "../common/common.hpp"
#include "../../../../state/state.hpp"
#include "../../../../io/config/helper/helper.hpp"

#include <cstdlib>
#include <iomanip>
#include <sstream>
#include <ctime>

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