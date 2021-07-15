#pragma once

#include <map>
#include <tuple>
#include <string>
#include <ncurses.h>
#include <boost/optional.hpp>

class ColorInterface
{
public:
    virtual void set(void *) = 0;

    virtual void remove(void *) = 0;
};

// class Colors
// {
// public:
//     void init();

//     void set(ColorInterface *color);

//     void remove(ColorInterface *color);
// };

class ThemeStorage
{
protected:
   



    std::map<std::string, int> font_themes = {
        {"BLACK", 100},
        {"RED", 101},
        {"GREEN", 102},
        {"YELLOW", 103},
        {"BLUE", 104},
        {"MAGENTA", 105},
        {"CYAN", 106},
        {"WHITE", 107},
    };
};

class Manager
{
protected:
    std::map<int, int> themes_used_by_buffers;
    int current_buffer;

public:
    void useBuffer(int id);
};

class FontTheme : public Manager, public ThemeStorage
{
public:
    void set_font_theme(std::string);

    void remove_font_theme(std::string);

    boost::optional<std::tuple<int, int>> get_font_theme_by_string(std::string color);
};

class ScreenTheme : public ThemeStorage
{
public:
    void set_screen_theme(int color_pair, int id = 0);

    void remove_screen_theme(int color_pair);

    void set_screen_theme_by_string(std::string color_pair);
};

// class Colors : public ScreenTheme, public FontTheme
// {
// };

extern Colors *_COLORS;