#include "./input.hpp"

int InputOperation::getPriority() {
    return SCHEDULER_PRIORITY_2;
};

int InputOperation::handleExec() {
    auto window = State::getWindowState()->getWindow();

//    wchar_t* symbol = Window::getSymbolAsChar(window);

//    wchar_t* ch = (wchar_t*)unctrl(wgetch(window));
//
//    waddch(window, *ch);
//
//    wrefresh(window);
//

//    const char *printable = unctrl(wgetch(window));  // Get printable version
//
//    // Print each character of the string using waddch
//    for (int i = 0; printable[i] != '\0'; i++) {
//        waddch(window, printable[i]);
//    }
//
//







    wint_t symbol;

    wget_wch(window, &symbol);

    if(std::find(
            FORBIDDEN_SYMBOLS.begin(), FORBIDDEN_SYMBOLS.end(), symbol) == FORBIDDEN_SYMBOLS.end()) {
        mvwprintw(window, 10, 10, "%lc", symbol);

        wrefresh(window);
    }















//        switch (ch) {
//            case KEY_UP:
//                printw("Up arrow pressed\n");
//                break;
//            case KEY_DOWN:
//                printw("Down arrow pressed\n");
//                break;
//            default:
//                printw("Key code: %d, Character: %c\n", ch, ch);
//                break;
//        }


//    std::cout << ch << std::endl;

//    counter += 2;

//    mvwaddwstr(window, 10, 10, (const wchar_t *)ch);

//    mvwaddw(window, symbol);

//    wprintw(State::getWindow(), std::to_string(ch).c_str());

    return EXIT_SUCCESS;
}

int InputOperation::handleExit() {
    return EXIT_SUCCESS;
}