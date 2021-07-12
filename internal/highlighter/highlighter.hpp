#pragma once

#include <map>
#include <tuple>
#include <string>

std::string strip(int startPos, std::string src);

typedef struct
{
    std::string type;
    std::string value;
    int position;
} Token;

class Lexer
{
private:
    std::tuple<int, int, int> position;
    void setPosition(int strPos, int y, int x);
    std::tuple<int, int, int> getPosition();
    std::vector<Token> allTokens();

protected:
public:
    std::vector<Token> analiseCode();
};

class Parser
{
};

class Highlighter : public Lexer
{
};

extern Highlighter *_HIGHLIGHTER;