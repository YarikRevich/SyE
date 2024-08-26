#include "./helper.hpp"

bool ConfigHelper::isWidgetActive(std::string value) {
    auto widgets = ConfigLoader::getConfigEntity()->getWidgets();

    auto iter = std::find_if(
            widgets.begin(),
            widgets.end(),
            [&](std::string& widget) {
                return widget == value;
            });

    return iter != widgets.end();
};

