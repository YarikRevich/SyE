#include "handler.hpp"

Handler::Handler(int argc, char **argv) : argc(argc), argv(argv) {
    this->argumentParser = new args::ArgumentParser("CLI text editor.\nStand with Ukraine! https://github.com/vshymanskyy/StandWithUkraine/blob/main/docs/README.md");
    this->validator = new Validator(argumentParser);

    this->positional = new args::Positional<std::string>(*argumentParser, "files", "File to be edited");
    this->configRoot = new args::ValueFlag<std::string>(*argumentParser, "config-root", "Path of configuration root", {"config-root"});
    this->help = new Help(argumentParser);
    
    this->entry = new Entry(positional, configRoot);
}

int Handler::run() {
    try
    {
        argumentParser->ParseCLI(argc, argv);
    }
    catch (...)
    {
        if (validator->handleArgumentParser(std::current_exception()) != EXIT_SUCCESS){
            return EXIT_FAILURE;
        };
    }

    if (positional->Get().empty()) {
        argumentParser->Help(std::cout);
        
        return EXIT_SUCCESS;
    }

    return entry->handle();
}