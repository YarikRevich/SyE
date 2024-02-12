#include "entry.hpp"

#include "../../io/helper/helper.hpp"

int Entry::handle() {
    Signal::init();

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

    std::cout << ConfigLoader::getConfigEntity()->getWidgets().size() << std::endl;

    Tools::startIndefiniteSpinner();

    return EXIT_SUCCESS;
}