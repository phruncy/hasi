#pragma once

#include <unordered_map>
#include "Token.h"

namespace hasi
{
    static const std::unordered_map<std::string, TokenType> keywords = 
    {
        {"or", TokenType::CONDITIONAL_OR},
        {"and", TokenType::CONDITIONAL_AND}
    };
}