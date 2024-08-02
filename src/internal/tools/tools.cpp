#include "tools.hpp"

#include <iostream>

std::string Tools::SPIN_CHARS = "/-\\|";

std::thread* Tools::spinWorker = nullptr;

std::atomic<bool> Tools::spinWorkerActive = false;

void Tools::startIndefiniteSpinnerRaw() {
#if defined(__linux__) || defined(__APPLE__)
    int i = 0;

    while (Tools::spinWorkerActive) {
        putchar(SPIN_CHARS[i % SPIN_CHARS.size()]);
        fflush(stdout);
        usleep(100000);
        putchar('\b');

        std::this_thread::yield();

        i++;
    }

#endif
}

void Tools::startIndefiniteSpinner() {
#if defined(__linux__) || defined(__APPLE__)
    if (!Tools::spinWorker) {
        Tools::spinWorker = new std::thread(Tools::startIndefiniteSpinnerRaw);

        Tools::spinWorker->detach();
    }

    Tools::spinWorkerActive = true;
#endif
}

void Tools::stopIndefiniteSpinner() {
#if defined(__linux__) || defined(__APPLE__)
    Tools::spinWorkerActive = false;

#endif
}