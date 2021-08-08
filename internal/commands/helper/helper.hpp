#pragma once

#include <vector>
#include <string>

class CommandWithArgsInterface
{
public:
    virtual void execute_with_params(std::string) const = 0;
};

class StandartCommandInterface
{
public:
    virtual void execute() const = 0;
};