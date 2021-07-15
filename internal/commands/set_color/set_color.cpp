#include "set_color.hpp"
#include "./../../colors/colors.hpp"

void Set_Color_Command::execute_with_params(std::vector<std::string> params)
{
    for (auto const i : params){
        _COLORS->set_theme_by_string(i);
    }
}