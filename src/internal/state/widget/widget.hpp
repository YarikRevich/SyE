#pragma once

#include "./time/time.hpp"

/**
 * Represents widget state holder.
 */
class WidgetState {
public:
    /**
     * Performs widget state initialization.
     */
    WidgetState();

    /**
    * Retrieves time widget state instance.
    *
    * @return retrieved time widget state instance.
    */
    TimeWidgetState* getTimeWidget();
private:
    /**
     * Represents time widget state.
    */
    TimeWidgetState* timeWidgetState;
};