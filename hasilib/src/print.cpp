#include <print.h>
#include <map>
#include <iostream>

namespace hasi::debug
{
    static const std::map<TokenType, std::string> tokenNames
    {
        { TokenType::PLUS, "PLUS"},
        { TokenType::MINUS, "MINUS" },
        { TokenType::STAR, "STAR" },
        { TokenType::SLASH, "SLASH" },
        { TokenType::LEFT_PAREN, "LEFT_PAREN" },
        { TokenType::RIGHT_PAREN, "RIGHT_PAREN" },
        { TokenType::BANG, "BANG"},
        { TokenType::BANG_EQUAL, "BANG_EQUAL"},
        { TokenType::EQUAL, "EQUAL"},
        { TokenType::EQUAL_EQUAL, "EQUAL_EQUAL"},
        { TokenType::GREATER, "GREATER"},
        { TokenType::GREATER_EQUAL, "GREATER_EQUAL"},
        { TokenType::LESS, "LESS"},
        { TokenType::LESS_EQUAL, "LESS_EQUAL"},  
        { TokenType::CONDITIONAL_AND, "CONDITIONAL_AND"},
        { TokenType::CONDITIONAL_OR, "CONDITIONAL_OR"},
        { TokenType::NUMBER, "NUMBER"},
        { TokenType::IDENTIFIER, "IDENTIFIER"},
        { TokenType::COMMA, "COMMA"}  
    };
    
    void printTokens(const std::vector<Token>& tokens)
    {
        for(const Token& t: tokens)
        {
            std::string name = tokenNames.contains(t.type) ? tokenNames.at(t.type) : "UNKNOWN_TOKEN";
            std::cout << "[" << name << "]";
        }
        std::cout << std::endl;
    }
}