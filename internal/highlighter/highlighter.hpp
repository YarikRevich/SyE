#pragma once

#include <map>
#include <tuple>
#include <regex>
#include <string>

std::string strip(int startPos, std::string src);

typedef struct
{
    int startPosition;
    std::string text;
} matchedWord;

typedef struct
{
    std::string type;
    std::string value;
    int position;
} Token;

typedef struct
{
    std::string pattern;
    std::regex reg;
} RegexPattern;

class Regex
{
protected:
    bool isAvailableSymbol(char symbol);
    std::string modifyPatternToExceptSpecialSymbols(std::string src);
    std::vector<matchedWord> findAllWords(std::string);
    bool wordExists(std::vector<matchedWord>, int x);
    std::vector<matchedWord> getWordsForDublicateCheck(std::string, std::string);
};

class LexPosition
{
protected:
    std::tuple<int, int, int> position;
    void setPosition(int strPos, int y, int x);
    std::tuple<int, int, int> getPosition();
};

class Lexer : public Regex, public LexPosition
{
public:
    void analiseCode();
};

class Highlighter : public Lexer
{
};

extern Highlighter *_HIGHLIGHTER;