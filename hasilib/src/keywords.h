#pragma once

#include <map>
#include "Token.h"

namespace hasi
{
    static const std::map<std::string, TokenType> keywords = 
    {
        {"or", TokenType::CONDITIONAL_OR},
        {"and", TokenType::CONDITIONAL_AND}
    };
}