#include <string>
#include "./../commands.hpp"

class Set_Color_Command : public CommandInterface
{
public:
    void execute_with_params(std::vector<std::string> params);
};