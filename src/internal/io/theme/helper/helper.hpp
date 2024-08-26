#pragma once

#include "../loader/loader.hpp"

/**
 * Represents helper used for theme operations.
*/
class ThemeHelper {
public:
    /**
     * Checks if theme is available to be used.
     *
     * @return result of the check.
     */
    static bool isAvailable();

    /**
     * Retrieves value for background effect.
     *
     * @return retrieved value for background effect.
     */
    static std::vector<int> getBackgroundEffectValue();

    /**
     * Retrieves value for font effect.
     *
     * @return retrieved value for font effect.
     */
    static std::vector<int> getFontEffectValue();

    /**
     * Converts given RGB color to ncurses palette view.
     *
     * @param value - given RGB color to be converted.
     * @return converted RGB color.
     */
    static int convertRGBColorToPalette(int value);
};