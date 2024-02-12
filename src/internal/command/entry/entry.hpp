#pragma once

#include <args/args.hxx>
#include "../../signal/signal.hpp"
#include "../../io/loader/config/config.hpp"
#include "../../io/loader/theme/theme.hpp"
#include "../../tools/tools.hpp"

#include <iostream>

/**
 * Represents entry handler.
*/
class Entry {
public:
    Entry(args::Positional<std::string>* positional, args::ValueFlag<std::string>* configRoot) 
        : positional(positional), 
          configRoot(configRoot) {};

    /**
     * Handles entry activation operation.
     * @return result of entry handler execution.
    */
    int handle();

private:
    args::Positional<std::string>* positional = NULL;
    args::ValueFlag<std::string>* configRoot = NULL;
};