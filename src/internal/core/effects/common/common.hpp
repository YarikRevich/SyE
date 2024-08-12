#pragma once

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