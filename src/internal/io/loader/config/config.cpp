#include "config.hpp"
#include <iostream>

std::vector<std::string> ConfigLoader::ConfigEntity::getWidgets() {
    return widgets;
}

void ConfigLoader::ConfigEntity::setWidgets(std::vector<std::string> widgets) {
    this->widgets = widgets;
}

int ConfigLoader::process(std::string root) {
    std::string path = IOHelper::getAbsolutePath(fs::path(root) / fs::path(CONFIG_FILE_NAME));
    if (!boost::filesystem::exists(path)){
        Logger::SetError(CONFIG_FILE_NOT_FOUND_EXCEPTION);

        return EXIT_FAILURE;
    }

    Logger::InvokeWarning(CONFIG_FILE_IDENTATION_WARNING);

    YAML::Node config = YAML::LoadFile(path.c_str());
    if (config[CONFIG_WIDGETS_KEY].IsDefined()){
        configEntity->setWidgets(config[CONFIG_WIDGETS_KEY].as<std::vector<std::string>>());
    }

    return EXIT_SUCCESS;
}

ConfigLoader::ConfigEntity* ConfigLoader::getConfigEntity() {
    return configEntity;
};

ConfigLoader::ConfigEntity* ConfigLoader::configEntity = new ConfigLoader::ConfigEntity();