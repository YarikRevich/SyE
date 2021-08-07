#include "applicator.hpp"
#include "./../w/w.hpp"
#include "./../z/z.hpp"

#include "./../../bufs/bufs.hpp"
#include "./../search/search.hpp"

#include "./../../editor_status/editor_status.hpp"

int Applicator::handleOneWordCommand(std::string command)
{
    std::transform(command.begin(), command.end(), command.begin(), [](char t) { return tolower(t);});

    if (command == "w")
    {
        W_Command().execute();
        return 1;
    }
    else if (command == "z")
    {
        Z_Command().execute();
        return 1;
    }
    return 0;
};

int Applicator::handleCommandWithArgs(std::string command)
{

    if (command[0] == '/')
    {
        Search_Command().execute_with_params(command.substr(1, command.length()));
        return 1;
    }
    return 0;
};

int Applicator::applyCommand(std::string command)
{
    int args_command = Applicator::handleCommandWithArgs(std::string(command.c_str()));
    int one_command = Applicator::handleOneWordCommand(command);
    return args_command || one_command;
};