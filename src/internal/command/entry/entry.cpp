#include "entry.hpp"

int Entry::handle() {
    std::string inputFile = IOHelper::getAbsolutePath(positional->Get());

    State::getEntryState()->setInputFile(inputFile);

    std::string configRootRaw;

    if (configRoot->Matched()) {
        configRootRaw = configRoot->Get();
    } else {
        configRootRaw = CONFIG_ROOT_PATH;
    }

    State::getEntryState()->setConfigRoot(configRootRaw);

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