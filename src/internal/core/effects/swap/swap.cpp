#include "./swap.hpp"

int SwapEffect::handleExec() {
    std::string path = IOHelper::getAbsolutePath(fs::path(State::getEntryState()->getConfigRoot()) / fs::path(THEME_CONFIG_PATH));
//    if (!boost::filesystem::is_directory(path)){
//        Logger::setError(THEME_DIRECTORY_NOT_FOUND_EXCEPTION);
//
//        return EXIT_FAILURE;
//    }

//    State::getFileState()->getInputFile();

    return EXIT_SUCCESS;
}

int SwapEffect::handleExit() {
    // TODO: close swap file.

    return EXIT_SUCCESS;
}