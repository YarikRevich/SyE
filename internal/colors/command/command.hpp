#include "./../colors.hpp"

#define COMMAND_THEME_DEFAULT 0

class CommandColor : public ColorInterface
{
private:
    std::map<int, std::tuple<int, int>> common_themes = {
        {COMMAND_THEME_DEFAULT, {COLOR_MAGENTA, COLOR_CYAN}},
    };

    std::map<std::string, int> compatible_themes = {
        {"default", COMMAND_THEME_DEFAULT}, 
    };

public:
    void set(void *);

    void remove(void *);
}