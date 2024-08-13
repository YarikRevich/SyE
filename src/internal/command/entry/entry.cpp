#include "entry.hpp"

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

    auto effects = State::getEffects();

    if (effects->process() != EXIT_SUCCESS) {
        return EXIT_FAILURE;
    }

    auto scheduler = State::getScheduler();

    if (scheduler->process() != EXIT_SUCCESS) {
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}