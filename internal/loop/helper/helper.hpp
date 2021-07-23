#pragma once

#include <vector>
#include <functional>

class Middleware
{
private:
    std::function<void()> middleware;

public:
    Middleware(std::function<void()> middleware);
    void use();
};

class MiddlwareExecutor
{
public:
    MiddlwareExecutor(std::vector<Middleware>);
};
