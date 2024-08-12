#pragma once

/**
* Represents scheduler operation interface.
*/
class SchedulerOperation {
public:
    /**
     * Handles operation execution.
     *
     * @return result of the operation execution.
     */
    virtual int handleExec() = 0;
};