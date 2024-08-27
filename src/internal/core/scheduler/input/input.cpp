#include "./input.hpp"

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

    while (true) {
        wget_wch(window, &symbol);

        if(std::find(FORBIDDEN_SYMBOLS.begin(), FORBIDDEN_SYMBOLS.end(), symbol) == FORBIDDEN_SYMBOLS.end()) {



            mvwprintw(window, 10, 10, "%lc", symbol);


//            wchar_t wch[2];
//
//            wch[0] = symbol;
//            wch[1] = L'\0';

//            mvwaddwstr(window, 10, counter, wch);
//            mvwinwstr(window, 10, 10, wch);

//            mvwaddch(window, 10, counter, symbol);

//            waddch(window, symbol);

            wrefresh(window);

//            wclear(window);

//            wmove(window, 10, counter);

//            std::cout << symbol << std::endl;

            // TODO: perform further filtering.
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
    }


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