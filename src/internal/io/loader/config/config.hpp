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

#include "../../helper/helper.hpp"
#include "../../../logger/logger.hpp"

/**
 * Represents loader of the configuration file.
*/
class ConfigLoader {
public:
    /**
     * Represents configuration file entity.
    */
    class ConfigEntity {
    public:
        /**
         * Retrieves bar widget names, which should be enabled.
         * 
         * @return retrieved widget names.
        */
        std::vector<std::string> getWidgets();

        /**
         * Sets bar widget names, which should be enabled.
         * 
         * @param widgets - given widget names to be enabled.
        */
        void setWidgets(std::vector<std::string> widgets);
    private:
        /**
         * Represents names of the widgets, which need to be enabled.
        */
        std::vector<std::string> widgets;
    };

    /**
     * Loads configuration file at the given location.
     * 
     * @param root - given configuration files location root.
     * @return result of the configuration loader execution.
    */
    static int process(std::string root);

    /**
     * Retrieves parsed configuration file entity.
     * 
     * @return parsed configuration file entity.
    */
    static ConfigEntity* getConfigEntity();
private:
    /**
     * Represents parsed configuration file entity.
    */
    static ConfigEntity* configEntity;

    
};

/**
 * Represents configuration files loader validator.
*/
class ConfigLoaderValidator {
public:
    /**
     * Checks if the given configuration widgets to be enabled are supported.
     * 
     * @param extensions - given configuration widgets to be enabled.
     * @return result of the validation.
    */
    static bool validateEnabledWidgetsSupport(std::vector<std::string>& widgets);

    /**
     * Checks if the given configuration supported widgets don't repeat.
     * 
     * @param extensions - given configuration supported widgets.
     * @return result of the validation.
    */
    static bool validateWidgetsRepeat(std::vector<std::string>& widgets);
};