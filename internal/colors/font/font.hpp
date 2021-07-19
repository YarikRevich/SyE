#pragma once

#include "./../colors.hpp"

class FontColor
{
private:

    std::tuple<int, int> current_theme;
public:
    void set(std::string);

    // void set_by_string(std::string theme);

    void remove(std::string);

    void set_current_theme(std::tuple<int, int>);

    std::tuple<int, int> get_current_theme();
};

extern FontColor *_FONT_COLOR;