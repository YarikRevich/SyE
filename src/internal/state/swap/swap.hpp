#pragma once

/**
 * Represents swap state holder.
 */
class SwapState {
public:
    /**
    * Retrieves previous swap presence state.
    *
    * @return retrieved previous swap presence state.
    */
    bool getPreviousPresent();

    /**
     * Sets previous swap presence state.
     *
     * @param value - previous swap presence state to be set.
     */
    void setPreviousPresent(bool value);
private:
    /**
     * Represents terminal instance.
    */
    bool previousPresent;
};