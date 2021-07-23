#pragma once

#include <vector>
#include <string>

class CommandWithArgsInterface
{
public:
    virtual void execute_with_params(std::string) = 0;
};

class StandartCommandInterface
{
public:
    virtual void execute() = 0;
};