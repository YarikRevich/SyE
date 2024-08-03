#include "spinner.hpp"

#include <iostream>

std::string Spinner::SPIN_CHARS = "/-\\|";

std::thread* Spinner::spinWorker = NULL;

std::atomic<bool> Spinner::spinWorkerActive = false;

void Spinner::startIndefiniteSpinner() {
#if defined(__linux__) || defined(__APPLE__)
    if (!Spinner::spinWorker) {
        Spinner::spinWorker = new std::thread(Spinner::startIndefiniteSpinnerRaw);

        Spinner::spinWorker->detach();
    }

    Spinner::spinWorkerActive = true;
#endif
}

void Spinner::stopIndefiniteSpinner() {
#if defined(__linux__) || defined(__APPLE__)
    Spinner::spinWorkerActive = false;

#endif
}

void Spinner::startIndefiniteSpinnerRaw() {
#if defined(__linux__) || defined(__APPLE__)
    int i = 0;

    while (Spinner::spinWorkerActive) {
        putchar(SPIN_CHARS[i % SPIN_CHARS.size()]);
        fflush(stdout);
        usleep(100000);
        putchar('\b');

        std::this_thread::yield();

        i++;
    }

#endif
}