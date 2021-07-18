#include <regex>
#include <vector>
#include <string>
#include <iterator>
#include <iostream>
#include <ctype.h>
#include "highlighter.hpp"
#include "./../bufs/bufs.hpp"
#include "./../files/configs/syntax_config/syntax_config.hpp"

std::string strip(int startPos, std::string src)
{
    std::string res;
    for (int i = startPos; i < src.size(); i++)
    {
        res += src[i];
    };
    return res;
};

bool Regex::isAvailableSymbol(char symbol)
{
    return std::isalnum(symbol);
};

std::string Regex::modifyPatternToExceptSpecialSymbols(std::string src)
{
    std::string res;
    for (int i = 0; i < src.size(); i++)
    {
        if (this->isAvailableSymbol(src[i]))
        {
            res += src[i];
        }
        else
        {
            res.append("\\").push_back(src[i]);
        };
    };
    return res;
};

std::vector<matchedWord> Regex::getWordsForDublicateCheck(std::string src, std::string pattern)
{
    std::vector<matchedWord> res;
    std::regex reg(this->modifyPatternToExceptSpecialSymbols(pattern));

    auto it = std::sregex_iterator(src.begin(), src.end(), reg);
    auto end = std::sregex_iterator();

    for (std::sregex_iterator i = it; i != end; i++)
    {

        matchedWord word;
        word.startPosition = i->position();
        word.text = i->str();

        res.push_back(word);
    };
    return res;
};

std::vector<matchedWord> Regex::findAllWords(std::string srcForFullProcessing)
{
    std::vector<matchedWord> res;
    std::string srcForSequenceProcessing(srcForFullProcessing);
    std::smatch sequenceMatch;
    std::regex s("\\S+");

    while (std::regex_search(srcForSequenceProcessing, sequenceMatch, s))
    {
        matchedWord word;

        word.text = sequenceMatch.str(0);

        auto dublicatedWords = this->getWordsForDublicateCheck(srcForFullProcessing, word.text);
        for (int d = 0; d < dublicatedWords.size(); d++)
        {
            if (!this->wordExists(res, dublicatedWords[d].startPosition))
            {
                word.startPosition = dublicatedWords[d].startPosition;
                break;
            };
        }

        res.push_back(word);

        srcForSequenceProcessing = sequenceMatch.suffix().str();
    };
    return res;
};

bool Regex::wordExists(std::vector<matchedWord> src, int x)
{
    for (int i = 0; i < src.size(); i++)
    {

        if (src[i].startPosition == x)
        {
            return true;
        }
    };
    return false;
};

void Lexer::analiseCode()
{
    std::vector<BufferAsString> bufferAsText = _INSERT__BUF->getBufAsStringWithYCoord();

    auto types = _SYNTAX_CONFIG.get().types;
    if (types.empty())
    {
        return;
    };

    auto [strPos, y, x] = this->getPosition();

    for (int i = 0; i < bufferAsText.size(); i++)
    {
        std::vector<matchedWord> allWords = this->findAllWords(bufferAsText[i].text);
        for (int q = 0; q < allWords.size(); q++)
        {
            for (int p = 0; p < types.size(); p++)
            {
                if (allWords[q].text == types[p].name)
                {
                    for (int c = 0; c < allWords[q].text.length(); c++)
                    {
                        _INSERT__BUF->setCellWithCoordsColor(bufferAsText[i].y, allWords[q].startPosition+c, types[p].color);
                    };
                };
            };
        };
    };
};

void LexPosition::setPosition(int strPos, int y, int x)
{
    this->position = {strPos, y, x};
};

std::tuple<int, int, int> LexPosition::getPosition()
{
    return this->position;
};

Highlighter *_HIGHLIGHTER = new Highlighter;