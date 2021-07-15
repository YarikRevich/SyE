#include "./../colors.hpp"


#define INSERT_THEME_DEFAULT 0
#define INSERT_THEME_BLUE 1

class InsertColor : public ColorInterface
{
private:
    std::map<int, std::tuple<int, int>> screen_themes = {
        {INSERT_THEME_DEFAULT, {COLOR_BLACK, COLOR_BLACK | COLOR_RED | COLOR_YELLOW}},
        {INSERT_THEME_BLUE, {COLOR_GREEN, COLOR_RED}},
    };

    std::map<std::string, int> compatible_themes = {
        {"default", INSERT_THEME_DEFAULT},
        {"blue", INSERT_THEME_BLUE},
    };

public:
    void set(void *);

    void remove(void *);
}