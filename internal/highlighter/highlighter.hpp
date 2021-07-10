#pragma once

#include <string>
#include <map>

typedef struct
{
    std::string type;
    std::string value;
    int position;
} Token;

typedef struct
{
    std::string name;
    std::string regexp;
    std::string color;
} TokenType;

std::vector<TokenType> allTokenTypes = {
    {name : "jk", regexp : "fg", color: "RED"},
};

class Lexer
{
private:
    std::string code;
    int position;
    std::vector<Token> allTokens();

public:
    std::vector<Token> analiseCode();
    bool nextToken();
};

class Parser
{
};

class Highlighter
{
};