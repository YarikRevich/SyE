#pragma once

#include <cstdio>

#if defined(__linux__) || defined(__APPLE__)
#include <unistd.h>
#endif

#include <string>
#include <thread>

/**
 * Represents terminal bash-like spinner.
 */
class Spinner {
public:
    /**
     * Start thread worker to run the indefinite command line spinner.
    */
    static void startIndefiniteSpinner();

    /**
     * Stops thread worker with the indefinite command line spinner.
    */
    static void stopIndefiniteSpinner();

private:
    /**
     * Represents a set of chars used to represent spinner.
     */
    static std::string SPIN_CHARS;

    /**
     * Represents thread worker used to operate spinner.
     */
    static std::thread* spinWorker;

    /**
     * Represents state of thread worker used to operate spinner.
     */
    static std::atomic<bool> spinWorkerActive;

    /**
     * Starts indefinite command line spinner.
    */
    static void startIndefiniteSpinnerRaw();
};