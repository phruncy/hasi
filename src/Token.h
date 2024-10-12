#pragma once

#include <string>

namespace hasi
{
    enum class TokenType
    {
        LEFT_PAREN,
        RIGHT_PAREN,

        PLUS,
        MINUS,
        STAR,
        SLASH,

        EQUAL,
        EQUAL_EQUAL,
        GREATER,
        GREATER_EQUALm,
        LESS,
        LESS_EQUAL,
        BANG,
        BANG_EQUAL,

        CONDITIONAL_OR,
        CONDITIONAL_AND,

        NUMBER,
        IDENTIFIER
    };

    struct TokenValue
    {
        float literal = 0;
    };
    
    struct Token
    {
        TokenType type;
        std::string lexeme;
        TokenValue value = null;
    };
}