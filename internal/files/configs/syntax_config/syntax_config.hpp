#pragma once

#include <string>
#include <vector>
#include "./../helper/helper.hpp"

typedef struct
{
    std::string name;
    std::string color;
} SyntaxConfigCellData;

typedef struct
{
    std::vector<SyntaxConfigCellData> types;
} SyntaxConfigData;

template <typename T>
class SyntaxConfig : public ConfigInterface<T>
{
private:
    std::vector<std::string> files;
    T data;
    void open();
    void read();

public:
    void open_and_read();
    T get();
};

extern SyntaxConfig<SyntaxConfigData> _SYNTAX_CONFIG;
