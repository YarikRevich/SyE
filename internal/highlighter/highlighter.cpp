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

std::vector<std::string> Lexer::findAllWords(std::string text)
{
    std::vector<std::string> res = {"Yarik"};
    // std::string subject(text);
    // std::smatch match;
    // std::regex s("\\S+");
    // while (std::regex_search(subject, match, s))
    // {
    //     res.push_back(match.str(0));
    //     subject = match.suffix().str();
    // };
    return res;
};

void Lexer::analiseCode()
{
    std::vector<BufferAsString> text = _INSERT__BUF->getBufAsStringWithYCoord();
    // while (1)
    // {
    auto types = _CONFIG_FILE->getConfig().types;
    if (types.empty())
    {
        return;
    };

    auto [strPos, y, x] = this->getPosition();

    for (int i = 0; i < text.size(); i++)
    {
        _LOG__BUF->addCellWithSymbolType(text[i].y, INT);
        _LOG__BUF->addCellWithSymbolType(10, CHAR);
    }
    // if (strPos >= text.length())
    // {

    //     return;
    // }

    // _LOG__BUF->addCellWithSymbolType(strPos, INT);
    // _LOG__BUF->addCellWithSymbolType(10, CHAR);
    // std::cmatch values;
    // for (auto const type : types)
    // {
    //     // _LOG__BUF->addCellWithSymbolType(type.color.size(), INT);
    //     // std::string s = strip(strPos, text).c_str();
    //     // for (auto const i : s)
    //     // {
    //     //     _LOG__BUF->addCellWithSymbolType(i, CHAR);
    //     // };

    //     if (std::regex_search(strip(strPos, text).c_str(), values, std::regex(type.regexp)))
    //     {
    //         _LOG__BUF->addCellWithSymbolType(8, INT);
    //         // break;
    //         this->setPosition(strPos += values[0].length(), y, x);
    //     };
    // };

    // if (values.empty())
    // {

    // std::vector<std::string> allWords = this->findAllWords(text);
    // this->setPosition(strPos += allWords[0].length(), y, x);
    // for (auto i : )

    // {
    //     for (auto q : i)
    //     {
    //         _LOG__BUF->addCellWithSymbolType(q, CHAR);
    //     };
    //     _LOG__BUF->addCellWithSymbolType(10, CHAR);
    // };
    // _LOG__BUF->addCellWithSymbolType(10, CHAR);

    // if (std::regex_search(strip(strPos, text).c_str(), values, std::regex("\\S+")))
    // {
    //     std::string s = values.str(0);
    //     for (auto const i : s)
    //     {
    //         _LOG__BUF->addCellWithSymbolType(i, CHAR);
    //     };
    //     _LOG__BUF->addCellWithSymbolType(10, CHAR);

    //     this->setPosition(strPos += values[0].length(), y, x);
    // };
    // };
    // };
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