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

        auto currentWindowSize = State::getWindowState()->getCurrentWindowSize();

        auto windowMaxSymbolAmount = Window::getWindowMaxSymbolAmount(currentWindowSize);

        auto currentCursorShift =
                (int)State::getInputState()->getGeneralSymbolsBuffer()->size() / windowMaxSymbolAmount;

        if (currentCursorShift == 0) {
            currentCursorShift = 1;
        }

        State::getInputState()->setCurrentCursorShift(currentCursorShift);
    }

    return EXIT_SUCCESS;
}

int ContentEffect::handleExit() {
    return EXIT_SUCCESS;
}