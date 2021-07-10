/*
    Contains general types and interfaces
    used over the project
*/

#pragma once

#include <vector>
#include <string>

//Interface for all handlers
class HandlerInterface
{
public:
    //Just handle pressed key
    virtual void handle(int ch) = 0;
};