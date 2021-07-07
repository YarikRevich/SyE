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

class AddonFileInterface
{
public:
    virtual void auto_save() = 0;
};

class FileInterface
{
protected:
    std::string file_name;
    FILE *file;

public:
    virtual void open(char n[]) = 0;

    virtual std::string read() = 0;

    virtual void save() = 0;

    virtual void close() = 0;
};
