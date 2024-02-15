#pragma once

#include <string>
#include <vector>

#include "../theme.hpp"

/**
 * Represents theme configuration files loader validator.
*/
class ThemeLoaderValidator {
public:
    /**
     * Checks if the given theme supported extensions don't repeat.
     * 
     * @param extensions - given theme supported extensions.
     * @return result of the validation.
    */
    static bool validateExtensionsRepeat(std::vector<std::string> extensions);

    /**
     * Checks if the given theme pattern definitions match specified
     * color with the available theme color definitions.
     * 
     * @param patterns - given theme pattern definitions.
     * @param color - given theme color definitions.
     * @return result of the validation.
    */
    static bool validatePatternColorMatching(
        std::vector<ThemeLoader::ThemeEntity::ThemePattern> patterns,
        std::vector<ThemeLoader::ThemeEntity::ThemeColor> colors);
};