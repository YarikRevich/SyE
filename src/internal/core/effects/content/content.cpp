#include "./content.hpp"

int ContentEffect::handleExec() {
    std::string path = IOHelper::getAbsolutePath(fs::path(State::getEntryState()->getInputFile()));

    if (IOHelper::getFileExists(path)) {
        std::wifstream stream(path);
        std::wstring data((std::istreambuf_iterator<wchar_t>(stream)),
                         std::istreambuf_iterator<wchar_t>());


    }

//    State::getEntryState()->getInputFile();

//    std::string path = IOHelper::getAbsolutePath(
//            fs::path(State::getEntryState()->getConfigRoot()) / fs::path(CONFIG_FILE_PATH) / fs::path(CONFIG_FILE_NAME));
//
//    if (!IOHelper::getFileExists(path)){
//        Logger::setError(CONFIG_FILE_NOT_FOUND_EXCEPTION);
//
//        return EXIT_FAILURE;
//    }

    return EXIT_SUCCESS;
}

int ContentEffect::handleExit() {
    return EXIT_SUCCESS;
}