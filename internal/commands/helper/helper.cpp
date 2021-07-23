#include <string>
#include <vector>

std::vector<std::string> getArgsOfCommand(std::string command, std::string directive)
{
    int cut_pos = command.find(directive);
    std::string not_formatted_args = command.substr(cut_pos, command.size() - 1);

    std::vector<std::string> formatted_args;
    while ((cut_pos = not_formatted_args.find(" ")) != command.npos)
    {
        std::string arg = not_formatted_args.substr(0, cut_pos);
        formatted_args.push_back(arg);
        not_formatted_args.erase(0, cut_pos+1);
    };
    return formatted_args;
};