#pragma once

#include <map>
#include <tuple>
#include <string>
#include <ncurses.h>

class StateInterface
{
private:
    std::tuple<int, int> current_theme;

public:
    virtual void set_current_theme(std::tuple<int, int>) = 0;

    virtual std::tuple<int, int> get_current_theme() = 0;
};

class ColorInterface : public StateInterface
{
public:
    virtual void set(void *) = 0;

    virtual void set_by_string(std::string theme) = 0;

    virtual void remove(void * = NULL) = 0;
};

class ColorWrapper
{
private:
    ColorInterface *src;

public:
    ColorWrapper(ColorInterface *src);

    void remove(void *color);

    std::tuple<int, int> get_current_theme();
};

// class Manager
// {
// protected:
//     std::map<int, int> themes_used_by_buffers;
//     int current_buffer;

// public:
//     void useBuffer(int id);
// };

// class FontTheme : public Manager, public ThemeStorage
// {
// public:
//     void set_font_theme(std::string);

//     void remove_font_theme(std::string);

//    // boost::optional<std::tuple<int, int>> get_font_theme_by_string(std::string color);
// };

// class ScreenTheme : public ThemeStorage
// {
// public:
//     void set_screen_theme(int color_pair, int id = 0);

//     void remove_screen_theme(int color_pair);

//     //void set_screen_theme_by_string(std::string color_pair);
// };

// class Colors : public ScreenTheme, public FontTheme
// {
// };