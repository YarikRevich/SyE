#include "highlighter.hpp"
#include <vector>
#include <regex>

std::vector<Token> Lexer::analiseCode(){};

bool Lexer::nextToken()
{
    if (this->position == this->code.length())
    {
        return false;
    }
    for (auto const token : allTokenTypes)
    {
        std::smatch values;
        if (std::regex_search(token.name, values, token.regexp))
        {
            for (auto const value : values)
            {
            };
        };
    }
};