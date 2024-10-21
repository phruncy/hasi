#pragma once

#include <string>
#include <cfloat>

typedef float TokenValue;

constexpr TokenValue HASI_NOVALUE = FLT_MAX;

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
        GREATER_EQUAL,
        LESS,
        LESS_EQUAL,
        BANG,
        BANG_EQUAL,

        CONDITIONAL_OR,
        CONDITIONAL_AND,

        NUMBER,
        IDENTIFIER
    };
    
    struct Token
    {
        TokenType type;
        std::string lexeme;
        TokenValue value;
    };
}