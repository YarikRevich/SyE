#include "entry.hpp"

#include "../../io/helper/helper.hpp"

#include <iostream>

int Entry::handle() {
    std::string inputFile = IOHelper::getAbsolutePath(positional->Get());

    std::string configRootRaw;

    if (configRoot->Matched()) {
        configRootRaw = configRoot->Get();
    } else {
        configRootRaw = CONFIG_ROOT_PATH;
    }

    if (ConfigLoader::process(configRootRaw) != EXIT_SUCCESS) {
        return EXIT_FAILURE;
    };

    std::string inputFileExtension = IOHelper::getFileExtension(inputFile);
    
    if (ThemeLoader::process(inputFileExtension, configRootRaw) != EXIT_SUCCESS) {
        return EXIT_FAILURE;
    };

    Tools::startIndefiniteSpinner();

    Signal::init();
    Render::init();

    Tools::stopIndefiniteSpinner();

    Render::renderWindow();

    return EXIT_SUCCESS;
}