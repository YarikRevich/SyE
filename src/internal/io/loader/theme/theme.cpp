#include "theme.hpp"

std::string ThemeLoader::ThemeEntity::ThemeColor::getName() {
    return name;
}

void ThemeLoader::ThemeEntity::ThemeColor::setName(std::string name) {
    this->name = name;
}

std::string ThemeLoader::ThemeEntity::ThemeColor::getValue() {
    return value;
}

void ThemeLoader::ThemeEntity::ThemeColor::setValue(std::string value) {
    this->value = value;
}

std::vector<std::string> ThemeLoader::ThemeEntity::getExtensions() {
    return extensions;
}

void ThemeLoader::ThemeEntity::setExtensions(std::vector<std::string> extensions) {
    this->extensions = extensions;
}

std::vector<ThemeLoader::ThemeEntity::ThemeColor> ThemeLoader::ThemeEntity::getColors() {
    return colors;
}

void ThemeLoader::ThemeEntity::setColors(std::vector<ThemeLoader::ThemeEntity::ThemeColor> colors) {
    this->colors = colors;
}

int ThemeLoader::process(std::string extension, std::string root) {
    if (extension == THEME_EXTENSION_NONE) {
        return;
    }

    std::string path = IOHelper::getAbsolutePath(fs::path(root) / fs::path(THEME_CONFIG_PATH));
    if (!boost::filesystem::exists(path)){
        Logger::SetError(THEME_DIRECTORY_NOT_FOUND_EXCEPTION);

        return EXIT_FAILURE;
    }

    YAML::Node config;

    fs::directory_iterator end;

    for (fs::directory_iterator iter(path); iter != end; ++iter) {
        config = YAML::LoadFile(iter->path());
        if (config[THEME_CONFIG_EXTENSIONS_KEY].IsDefined()){
            themeEntity->setExtensions(config[THEME_CONFIG_EXTENSIONS_KEY].as<std::vector<std::string>>());
        } else {
            continue;
        }

        if(auto iter = std::find_if(
            themeEntity->getExtensions().begin(), 
            themeEntity->getExtensions().end(), 
            [&](const std::string& value) { return value == extension;}); iter == std::end(themeEntity->getExtensions())) {
            continue;
        }

        if (config[THEME_CONFIG_COLORS_KEY].IsDefined()){
            themeEntity->setColors(config[THEME_CONFIG_COLORS_KEY].as<std::vector<ThemeLoader::ThemeEntity::ThemeColor>>());
        }

        // if (config[])

    //     add_compile_definitions(THEME_CONFIG_EXTENSIONS_KEY="extensions")
	// add_compile_definitions(THEME_CONFIG_COLORS_KEY="colors")
	// add_compile_definitions(THEME_CONFIG_PATTERNS_KEY="patterns")
    }

    return EXIT_SUCCESS;
}

ThemeLoader::ThemeEntity* ThemeLoader::getThemeEntity() {
    return themeEntity;
};

ThemeLoader::ThemeEntity* ThemeLoader::themeEntity = new ThemeLoader::ThemeEntity();


namespace YAML
{
    bool convert<ThemeLoader::ThemeEntity::ThemeColor>::decode(const Node& node, ThemeLoader::ThemeEntity::ThemeColor& dst) {
        if (!node.IsSequence() || node.size() != 2){
			return false;
        }

        dst.setName(node[0].as<std::string>());
		dst.setValue(node[1].as<std::string>());
		return true;
    }
}