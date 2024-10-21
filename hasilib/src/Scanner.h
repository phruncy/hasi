#pragma once

#include <vector>
#include "Token.h"
namespace hasi
{
    class Scanner 
    {
        public:
            Scanner(std::string source) : _source(source) {}
            
            void scan();
            std::vector<Token>& getTokens() { return _tokens; }
        private:
            std::string _source;
            std::vector<Token> _tokens;

            uint32_t _start = 0;
            uint32_t _current = 0;
            bool _hadError = false;

            bool isAtEnd();
            void scanToken();
            void addToken(TokenType type, TokenValue value);
            char advance();
            bool match(char expected);
            void addNumber();
            void addIdentifier();
            char peek();
            char peekNext();
            bool isAlphaNumeric();
    };
}