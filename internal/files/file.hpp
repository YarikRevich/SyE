#pragma once

#include <map>
#include <vector>
#include <string>
#include <stdio.h>

struct configDataTypeCell
{
    std::string name;
    std::string regexp;
    std::string color;
};

typedef struct
{
    std::string extension;
    std::vector<configDataTypeCell> types;
} ConfigData;

class FileBase
{
protected:
    std::string file_name;
    FILE *file;
};

class ConfigBase
{
public:
    std::vector<FILE *> configs;
    ConfigData configData;
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

class ConfigReader
{
public:
    virtual ConfigData read_config() = 0;
};

class AutoSave
{
public:
    virtual void auto_save() = 0;
};