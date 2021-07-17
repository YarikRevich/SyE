#pragma once


#include <string>
#include <vector>
#include "./../config.hpp"

typedef struct
{
    std::vector<std::string> insert;
    std::vector<std::string> command;
    std::vector<std::string> effects;
} ThemeConfigData;

template <typename T>
class ThemeConfig : public ConfigInterface<T>
{
private:
    T data;

public:
    void open();
    void read();
    T get();
};

extern ThemeConfig<ThemeConfigData> _THEME_CONFIG;