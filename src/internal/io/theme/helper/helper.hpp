#pragma once

#include "../loader/loader.hpp"

//extensions:
//- "c"
//- "cc"
//- "cpp"
//- "cxx"
//- "hpp"
//- "hxx"
//colors:
//- name: red
//        value: [100, 120, 133]
//- name: blue
//        value: [ 23, 52, 190 ]
//effects:
//background: red
//        patterns:
//- regex: ^(class)\s*[a-zA-Z<!~?>]*\s*\{
//color: blue


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