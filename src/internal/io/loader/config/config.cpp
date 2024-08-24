#include "config.hpp"

std::vector<std::string> ConfigLoader::ConfigEntity::getWidgets() {
    return widgets;
}

void ConfigLoader::ConfigEntity::setWidgets(std::vector<std::string> widgets) {
    this->widgets = widgets;
}

int ConfigLoader::process() {
    std::string path = IOHelper::getAbsolutePath(
            fs::path(State::getEntryState()->getConfigRoot()) / fs::path(CONFIG_FILE_PATH) / fs::path(CONFIG_FILE_NAME));
    if (!boost::filesystem::exists(path)){
        Logger::setError(CONFIG_FILE_NOT_FOUND_EXCEPTION);

        return EXIT_FAILURE;
    }

    Logger::invokeWarning(CONFIG_FILE_IDENTATION_WARNING);

    YAML::Node config = YAML::LoadFile(path.c_str());
    if (config[CONFIG_WIDGETS_KEY].IsDefined()){
        auto tempWidgets = config[CONFIG_WIDGETS_KEY].as<std::vector<std::string>>();

        if (ConfigLoaderValidator::validateEnabledWidgetsSupport(tempWidgets)) {
            if (!ConfigLoaderValidator::validateWidgetsRepeat(tempWidgets)) {
                Logger::invokeWarning(CONFIG_FILE_WIDGETS_REPEAT_EXCEPTION);
            }

            configEntity->setWidgets(tempWidgets);
        } else {
            Logger::setError(CONFIG_FILE_WIDGET_NOT_SUPPORTED_EXCEPTION);

            return EXIT_FAILURE;
        }
    }

    return EXIT_SUCCESS;
}

ConfigLoader::ConfigEntity* ConfigLoader::getConfigEntity() {
    return configEntity;
};

ConfigLoader::ConfigEntity* ConfigLoader::configEntity = new ConfigLoader::ConfigEntity();

bool ConfigLoaderValidator::validateEnabledWidgetsSupport(std::vector<std::string>& widgets) {
    for (std::string& widget : widgets) {
        if (widget != WIDGET_TIME) {
            return false;
        }
    }

    return true;
}

bool ConfigLoaderValidator::validateWidgetsRepeat(std::vector<std::string>& widgets) {
    std::set<std::string> tempWidgets(widgets.begin(), widgets.end());
    return tempWidgets.size() == widgets.size();
};