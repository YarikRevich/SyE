#pragma once

#include <args/args.hxx>

/**
 * Represents built-in help command.
*/
class Help {
public:
    /**
     * Performs help command initialization.
     */
    Help(args::ArgumentParser*);

private:
    /**
     * Represents command instance.
     */
    args::HelpFlag* command = NULL;
};