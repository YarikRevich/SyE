#include "./content.hpp"

int ContentEffect::handleExec() {
    std::string path = IOHelper::getAbsolutePath(fs::path(State::getEntryState()->getInputFile()));

    if (IOHelper::getFileExists(path)) {
        std::wifstream stream(path);
        std::wstring data((std::istreambuf_iterator<wchar_t>(stream)),
                         std::istreambuf_iterator<wchar_t>());

        for (wchar_t value : data)
        {
            State::getInputState()->getGeneralSymbolsBuffer()->push_back(
                    new InputState::Symbol(value));
        }
    }

    return EXIT_SUCCESS;
}

int ContentEffect::handleExit() {
    return EXIT_SUCCESS;
}