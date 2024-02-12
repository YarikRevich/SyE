#pragma once

#include <args/args.hxx>

/**
 * Represents built-in help command.
*/
class Help {
public:
    Help(args::ArgumentParser*);

private:
    args::HelpFlag* command = NULL;
};