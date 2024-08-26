#pragma once

#include <yaml-cpp/yaml.h>
#include <boost/filesystem.hpp>
#ifdef __APPLE__
#include <filesystem>
namespace fs = std::filesystem;
#elif defined(__linux__)
#include <experimental/filesystem>
namespace fs = std::experimental::filesystem;
#endif

#include <string>
#include <vector>
#include <set>

#include "../../helper/helper.hpp"
#include "../../../logger/logger.hpp"
#include "../../../state/state.hpp"

/**
 * Represents loader of the theme configuration files.
*/
class ThemeLoader {
public:
    /**
     * Represents theme configuration file entity.
    */
    class ThemeEntity {
    public:
        /**
         * Represents theme color definition entity.
        */
        class ThemeColor {
        public:
            /**
             * Retrieves name of theme color definition.
             * 
             * @return retrieved name of theme color definition.
            */
            std::string getName();

            /**
             * Sets name of theme color definition.
             * 
             * @param name - given name of theme color definition.
            */
            void setName(std::string name);

            /**
             * Retrieves value of theme color definition.
             * 
             * @return retrieved value of theme color definition.
            */
            std::vector<int> getValue();

            /**
             * Sets value of theme color definition.
             * 
             * @param value - given value of theme color definition.
            */
            void setValue(std::vector<int> value);
        private:
            /**
             * Represents name of theme color definition.
            */
            std::string name;

            /**
             * Represents value of theme color definition.
            */
            std::vector<int> value;
        };

        /**
         * Represents theme pattern definition entity.
        */
        class ThemePattern {
        public:
            /**
             * Retrieves regex of theme pattern definition.
             * 
             * @return retrieved regex of theme pattern definition.
            */
            std::string getRegex();

            /**
             * Sets name of theme color definition.
             * 
             * @param name - given name of theme color definition.
            */
            void setRegex(std::string regex);

            /**
             * Retrieves color of theme pattern definition.
             * 
             * @return retrieved color of theme pattern definition.
            */
            std::string getColor();

            /**
             * Sets color of theme pattern definition.
             * 
             * @param value - given color of theme pattern definition.
            */
            void setColor(std::string value);
        private:
            /**
             * Represents regex of theme pattern definition.
            */
            std::string regex;

            /**
             * Represents color of theme pattern definition.
            */
            std::string color;
        };

        /**
         * Represents theme effects definition entity.
        */
        class ThemeEffects {
        public:
            /**
             * Retrieves background color of theme effects definition.
             * 
             * @return retrieved background color of theme effects definition.
            */
            std::string getBackground();

            /**
             * Sets background color of theme effects definition.
             * 
             * @param name - given background color of theme effects definition.
            */
            void setBackground(std::string background);

            /**
             * Retrieves font color of theme effects definition.
             *
             * @return retrieved font color of theme effects definition.
            */
            std::string getFont();

            /**
             * Sets font color of theme effects definition.
             *
             * @param name - given font color of theme effects definition.
            */
            void setFont(std::string font);
        private:
            /**
             * Represents background color value.
            */
            std::string background;

            /**
             * Represents font color value.
            */
            std::string font;
        };

        /**
         * Retrieves supported file extensions.
         * 
         * @return retrieved supported file extensions.
        */
        std::vector<std::string> getExtensions();

        /**
         * Sets supported file extensions.
         * 
         * @param widgets - given supported file extensions
        */
        void setExtensions(std::vector<std::string> extensions);

        /**
         * Retrieves theme color definitions.
         * 
         * @return retrieved theme color definitions.
        */
        std::vector<ThemeColor> getColors();

        /**
         * Sets theme color definitions.
         * 
         * @param colors - given theme color definitions.
        */
        void setColors(std::vector<ThemeColor> colors);

        /**
         * Retrieves theme effects definitions.
         * 
         * @return retrieved theme effects definitions.
        */
        ThemeEffects getEffects();

        /**
         * Sets theme effects definitions.
         * 
         * @param colors - given theme effects definitions.
        */
        void setEffects(ThemeEffects effects);

        /**
         * Retrieves theme pattern definitions.
         * 
         * @return retrieved theme pattern definitions.
        */
        std::vector<ThemePattern> getPatterns();

        /**
         * Sets theme pattern definitions.
         * 
         * @param colors - given theme pattern definitions.
        */
        void setPatterns(std::vector<ThemePattern> patterns);
    private:
        /**
         * Represents supported file extensions.
        */
        std::vector<std::string> extensions;

        /**
         * Represents theme color definitions.
        */
        std::vector<ThemeColor> colors;

        /**
         * Represents theme effects definitions.
        */
        ThemeEffects effects;

        /**
         * Represents theme pattern definitions.
        */
        std::vector<ThemePattern> patterns;
    };

    /**
     * Loads configuration files at the given location.
     *
     * @return result of the configuration loader execution.
    */
    static int process();

    /**
     * Retrieves selected parsed theme configuration file entity.
     * 
     * @return selected parsed theme configuration file entity.
    */
    static ThemeEntity* getThemeEntity();
private:
    /**
     * Represents selected parsed theme configuration file entity.
    */
    static ThemeEntity* themeEntity;
};

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
    static bool validateExtensionsRepeat(std::vector<std::string>& extensions);

    /**
     * Checks if the given theme color definitions are described correctly.
     * 
     * @param value - given theme color definition values.
     * @return result of the validation.
    */
    static bool validateColorValue(std::vector<ThemeLoader::ThemeEntity::ThemeColor>& value);

    /**
     * Checks if the given theme pattern definitions match specified
     * color with the available theme color definitions.
     * 
     * @param patterns - given theme pattern definitions.
     * @param color - given theme color definitions.
     * @return result of the validation.
    */
    static bool validatePatternColorMatching(
        std::vector<ThemeLoader::ThemeEntity::ThemePattern>& patterns,
        std::vector<ThemeLoader::ThemeEntity::ThemeColor>& colors);

    /**
     * Checks if the given theme effects definitions match specified
     * color with the available theme color definitions.
     * 
     * @param effects - given theme efects definitions.
     * @param color - given theme color definitions.
     * @return result of the validation.
    */
    static bool validateEffectColorMatching(
        ThemeLoader::ThemeEntity::ThemeEffects& effects,
        std::vector<ThemeLoader::ThemeEntity::ThemeColor>& colors);
};

/**
 * Definies custom converter for ThemeColor custom type definition.
*/
namespace YAML
{
    /**
     * Represents custom theme color definition converter.
    */
	template<>
	struct convert<ThemeLoader::ThemeEntity::ThemeColor>
	{
        /**
         * Decodes given raw YAML node to the ThemeColor definition entity.
         * 
         * @param node - given raw YAML node.
         * @param dst - destination ThemeColor definition entity.
         * @return result of the conversion.
        */
		static bool decode(const Node& node, ThemeLoader::ThemeEntity::ThemeColor& dst);
	};

    /**
     * Represents custom theme effects definition converter.
    */
	template<>
	struct convert<ThemeLoader::ThemeEntity::ThemeEffects>
	{
        /**
         * Decodes given raw YAML node to the ThemeEffects definition entity.
         * 
         * @param node - given raw YAML node.
         * @param dst - destination ThemeEffects definition entity.
         * @return result of the conversion.
        */
		static bool decode(const Node& node, ThemeLoader::ThemeEntity::ThemeEffects& dst);
	};

    /**
     * Represents custom theme pattern definition converter.
    */
	template<>
	struct convert<ThemeLoader::ThemeEntity::ThemePattern>
	{
        /**
         * Decodes given raw YAML node to the ThemePattern definition entity.
         * 
         * @param node - given raw YAML node.
         * @param dst - destination ThemePattern definition entity.
         * @return result of the conversion.
        */
		static bool decode(const Node& node, ThemeLoader::ThemeEntity::ThemePattern& dst);
	};
}