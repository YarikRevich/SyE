#include "entry.hpp"
#include "../../core/scheduler/operations/render/render.hpp"

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

    Spinner::startIndefiniteSpinner();

    Signal::init();
    Scheduler::init();

    Scheduler::addHandler(new Render());

    Spinner::stopIndefiniteSpinner();

    Scheduler::handleExec();

    return EXIT_SUCCESS;
}