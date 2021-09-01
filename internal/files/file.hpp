#pragma once

#include <map>
#include <vector>
#include <string>
#include <stdio.h>

class FileBase
{
protected:
    std::string file_name;
    FILE *file;
};

class Open
{
public:
    virtual void open(void *) = 0;
};

class Close
{
public:
    virtual void close() = 0;
};

class Read
{
public:
    virtual std::string read() = 0;
};

class Save
{
public:
    virtual void save() = 0;
};

class GetFileName
{
public:
    virtual std::string getFileName() = 0;
};

class ConfigReader
{
public:
    virtual void read_config() = 0;
};

class AutoSave
{
public:
    virtual void auto_save() = 0;
};