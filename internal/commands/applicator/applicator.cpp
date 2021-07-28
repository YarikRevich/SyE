#include "applicator.hpp"
#include "./../w/w.hpp"

#include "./../search/search.hpp"

#include "./../../editor_status/editor_status.hpp"

int Applicator::handleOneWordCommand(std::string command)
{
    std::transform(command.begin(), command.end(), command.begin(), [](char t)
                   { return tolower(t); });

    if (command == "w")
    {
        W_Command().execute();
        return 1;
    }
    return -1;
};

int Applicator::handleCommandWithArgs(std::string command)
{
    if (command[0] == '/')
    {
        Search_Command().execute_with_params(command.substr(1, command.length()));
        return 1;
    }
    return -1;
};

int Applicator::applyCommand(std::string command)
{
    return Applicator::handleCommandWithArgs(command) ||
           Applicator::handleOneWordCommand(command);
};