#pragma once

#include <string>
#include <vector>
#include <tuple>
#include "./../helper/helper.hpp"

typedef struct
{
    std::string name;
    std::tuple<std::string, std::string> insert;
    std::tuple<std::string, std::string> command;
    std::string effects;
} ThemeConfigData;

template <typename T>
class ThemeConfig : public ConfigInterface<T>
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

extern ThemeConfig<ThemeConfigData> _THEME_CONFIG;