#include "./window.hpp"

int WindowEffect::handleExec() {
    setlocale(LC_ALL, "uk_UA.UTF-8");
    initscr();
    start_color();
    cbreak();
    set_escdelay(FALSE);
    noecho();

    int x, y;
    getmaxyx(stdscr, y, x);

    auto window = newwin(y, x, 0, 0);

    State::getWindowState()->setWindow(window);

    nodelay(window, TRUE);
    scrollok(window, TRUE);
    keypad(window, TRUE);

    if (can_change_color() && has_colors()) {
        if (ThemeHelper::isAvailable()) {
            auto backgroundEffectValue = ThemeHelper::getBackgroundEffectValue();
            init_color(
                    BACKGROUND_COLOR,
                    ThemeHelper::convertRGBColorToPalette(backgroundEffectValue[0]),
                    ThemeHelper::convertRGBColorToPalette(backgroundEffectValue[1]),
                    ThemeHelper::convertRGBColorToPalette(backgroundEffectValue[2]));

            auto fontEffectValue = ThemeHelper::getFontEffectValue();
            init_color(
                    FONT_COLOR,
                    ThemeHelper::convertRGBColorToPalette(fontEffectValue[0]),
                    ThemeHelper::convertRGBColorToPalette(fontEffectValue[1]),
                    ThemeHelper::convertRGBColorToPalette(fontEffectValue[2]));

            init_pair(SELECTED_THEME, FONT_COLOR, BACKGROUND_COLOR);

            wbkgd(window, COLOR_PAIR(SELECTED_THEME));
        }
    }

    // TODO: fill all the background with some sort of color.

    return EXIT_SUCCESS;
}

int WindowEffect::handleExit() {
    endwin();
    delwin(State::getWindowState()->getWindow());

    return EXIT_SUCCESS;
}