#pragma once

#include <map>
#include <vector>
#include <string>
#include <stdio.h>

typedef struct
{
    std::string name;
    std::string regexp;
    std::string color;
} configDataTypeCell;

typedef struct
{
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
    std::vector<std::string> configs;
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

class GetConfig
{
public:
    virtual ConfigData getConfig() = 0;
};

class AutoSave
{
public:
    virtual void auto_save() = 0;
};