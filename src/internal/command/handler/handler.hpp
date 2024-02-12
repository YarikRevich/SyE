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
    Handler(int argc, char **argv);

    /**
     * Starts command handler execution. 
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