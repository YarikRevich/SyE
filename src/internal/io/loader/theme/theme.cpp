#include "theme.hpp"

std::string ThemeLoader::ThemeEntity::ThemeColor::getName() {
    return name;
}

void ThemeLoader::ThemeEntity::ThemeColor::setName(std::string name) {
    this->name = name;
}

std::vector<int> ThemeLoader::ThemeEntity::ThemeColor::getValue() {
    return value;
}

void ThemeLoader::ThemeEntity::ThemeColor::setValue(std::vector<int> value) {
    this->value = value;
}

std::string ThemeLoader::ThemeEntity::ThemePattern::getRegex() {
    return regex;
}

void ThemeLoader::ThemeEntity::ThemePattern::setRegex(std::string regex) {
    this->regex = regex;
}

std::string ThemeLoader::ThemeEntity::ThemePattern::getColor() {
    return color;
}

void ThemeLoader::ThemeEntity::ThemePattern::setColor(std::string color) {
    this->color = color;
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

std::vector<ThemeLoader::ThemeEntity::ThemePattern> ThemeLoader::ThemeEntity::getPatterns() {
    return patterns;
}

void ThemeLoader::ThemeEntity::setPatterns(std::vector<ThemeLoader::ThemeEntity::ThemePattern> patterns) {
    this->patterns = patterns;
}

int ThemeLoader::process(std::string extension, std::string root) {
    if (extension == THEME_EXTENSION_NONE) {
        Logger::InvokeWarning(DEFAULT_THEME_USAGE_WARNING);

        return EXIT_SUCCESS;
    }

    std::string path = IOHelper::getAbsolutePath(fs::path(root) / fs::path(THEME_CONFIG_PATH));
    if (!boost::filesystem::is_directory(path)){
        Logger::SetError(THEME_DIRECTORY_NOT_FOUND_EXCEPTION);

        return EXIT_FAILURE;
    }

    YAML::Node config;

    fs::directory_iterator end;

    for (fs::directory_iterator iter(path); iter != end; ++iter) {
        config = YAML::LoadFile(iter->path());

        std::vector<std::string> tempExtensions;
        if (config[THEME_CONFIG_EXTENSIONS_KEY].IsDefined()){
            tempExtensions = config[THEME_CONFIG_EXTENSIONS_KEY].as<std::vector<std::string>>();

            if(auto iter = std::find_if(
                tempExtensions.begin(), 
                tempExtensions.end(), 
                [&](const std::string& value) { return value == extension;}); iter == std::end(tempExtensions)) {
                continue;
            }
        } else {
            continue;
        }

        themeEntity->setExtensions(tempExtensions);

        if (config[THEME_CONFIG_COLORS_KEY].IsDefined()){
            themeEntity->setColors(config[THEME_CONFIG_COLORS_KEY].as<std::vector<ThemeLoader::ThemeEntity::ThemeColor>>());
        }

        if (config[THEME_CONFIG_PATTERNS_KEY].IsDefined()){
            themeEntity->setPatterns(config[THEME_CONFIG_PATTERNS_KEY].as<std::vector<ThemeLoader::ThemeEntity::ThemePattern>>());
        }

        Logger::InvokeInfo(CUSTOM_THEME_SELECTED);
        break;
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
		dst.setValue(node[1].as<std::vector<int>>());
		return true;
    }

    bool convert<ThemeLoader::ThemeEntity::ThemePattern>::decode(const Node& node, ThemeLoader::ThemeEntity::ThemePattern& dst) {
        if (!node.IsSequence() || node.size() != 2){
			return false;
        }

        dst.setRegex(node[0].as<std::string>());
		dst.setColor(node[1].as<std::string>());
		return true;
    }
}