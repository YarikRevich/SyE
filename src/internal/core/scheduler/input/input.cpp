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


    wchar_t ch;

    while ((ch = (wchar_t)wgetch(window)) != 'q') {  // Press 'q' to quit
        if (ch != 410) {
            if (ch == KEY_BACKSPACE) {
                waddch(window, KEY_BACKSPACE);
            }
//            printw("Key code: %d, Character: %c\n", ch, ch);
            waddch(window, ch);
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
    }


//    std::cout << ch << std::endl;

//    counter += 2;

//    mvwaddwstr(window, 10, 10, (const wchar_t *)ch);

//    mvwaddw(window, symbol);

//    (window, );

//    wprintw(State::getWindow(), std::to_string(ch).c_str());

    return EXIT_SUCCESS;
}

int InputOperation::handleExit() {
    return EXIT_SUCCESS;
}