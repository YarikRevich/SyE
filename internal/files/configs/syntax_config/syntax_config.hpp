#pragma once

#include <string>
#include <vector>
#include "./../config.hpp"

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
// private:
//     T data;

public:
    void open();
    void read();
    T get();
};

extern SyntaxConfig<SyntaxConfigData> _SYNTAX_CONFIG;
