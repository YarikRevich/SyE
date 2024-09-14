#pragma once

/**
* Represents scheduler operation interface.
*/
class InputMode {
public:
    /**
     * Returns mode type.
     *
     * @return retrieved mode type.
     */
    virtual int getType() = 0;

    /**
     * Handles operation execution.
     *
     * @return result of the operation execution.
     */
    virtual int handleExec() = 0;
};