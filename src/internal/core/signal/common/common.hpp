#pragma once

/**
* Represents signal operation interface.
*/
class SignalOperation {
public:
    /**
     * Handles application exit signal.
     *
     * @return result of the execution.
     */
    virtual int handleExit() = 0;
};