#include "./helper.hpp"

#include <iostream>

bool ThemeHelper::isAvailable() {
    return ThemeLoader::getThemeEntity() != NULL;
}

std::vector<int> ThemeHelper::getBackgroundEffectValue() {
    auto colors = ThemeLoader::getThemeEntity()->getColors();

    auto iter = std::find_if(
            colors.begin(),
            colors.end(),
            [&](ThemeLoader::ThemeEntity::ThemeColor& value) {
                return value.getName() == ThemeLoader::getThemeEntity()->getEffects().getBackground();
            }
    );

    return iter->getValue();
}

std::vector<int> ThemeHelper::getFontEffectValue() {
    auto colors = ThemeLoader::getThemeEntity()->getColors();

    auto iter = std::find_if(
            colors.begin(),
            colors.end(),
            [&](ThemeLoader::ThemeEntity::ThemeColor& value) {
                return value.getName() == ThemeLoader::getThemeEntity()->getEffects().getFont();
            }
    );

    return iter->getValue();
}

int ThemeHelper::convertRGBColorToPalette(int value) {
    return value * 1000 / 255;
}