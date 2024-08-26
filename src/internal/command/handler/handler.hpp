#pragma once

#include <args/args.hxx>
#include "../help/help.hpp"
#include "../validator/validator.hpp"
#include "../entry/entry.hpp"

#include <iostream>

using namespace std;

/**
 * Provides access to operate CLI command handlers.
*/
class Handler {
public:
    /**
     * Performs handle initialization.
     *
     * @param argc - amount of the given arguments.
     * @param argv - given arguments.
     */
    Handler(int argc, char **argv);

    /**
     * Starts command handler execution.
     *
     * @return result of handler execution.
    */
    int run();

private:
    args::ArgumentParser* argumentParser = NULL;
    args::Positional<std::string>* positional = NULL;
    args::ValueFlag<std::string>* configRoot = NULL;

    Help* help = NULL;
    Validator* validator = NULL;

    Entry* entry = NULL;

    int argc;
    char **argv;
};