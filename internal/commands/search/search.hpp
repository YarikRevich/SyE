#include "./../helper/helper.hpp"

class Search_Command : public CommandWithArgsInterface
{
public:
    void execute_with_params(std::string);
};