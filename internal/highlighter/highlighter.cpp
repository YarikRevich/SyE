#include <regex>
#include <vector>
#include "highlighter.hpp"
#include "./../bufs/bufs.hpp"
#include "./../files/config/config.hpp"

std::string strip(int startPos, std::string src)
{
    std::string res;
    for (int i = startPos; i < src.size(); i++)
    {
        res += src[i];
    };
    return res;
};

std::vector<Token> Lexer::analiseCode()
{
    std::string text = _INSERT__BUF->getBufAsString();
    while (1)
    {
             _LOG__BUF->addCellWithSymbolType(1, INT);
        for (auto const type : _CONFIG_FILE->getConfig().types)
        {
            auto [strPos, y, x] = this->getPosition();
            if (strPos >= text.length())
            {
                return {}; 
            }

       
            std::cmatch values;
            if (std::regex_search(strip(strPos, text).c_str(), values, std::regex("^" + type.regexp)))
            {

                this->setPosition(strPos += values[0].length(), y, x);
            };
        };
    };
};

void Lexer::setPosition(int strPos, int y, int x)
{
    this->position = {strPos, y, x};
};

std::tuple<int, int, int> Lexer::getPosition()
{
    return this->position;
};

Highlighter *_HIGHLIGHTER = new Highlighter;