#pragma once

#include <vector>
#include "Token.h"
namespace hasi
{
    class Scanner 
    {
        public:
            Scanner(const std::string& source) : _source(source) {}
            
            void scan();
            bool hadError() const { return _hadError; }
            std::vector<Token>& getTokens() { return _tokens; }
        private:
            const std::string& _source;
            std::vector<Token> _tokens;

            uint32_t _start = 0;
            uint32_t _current = 0;
            uint32_t _line = 0;
            bool _hadError = false;

            bool isAtEnd() const;
            void scanToken();
            void addToken(TokenType type, TokenValue value);
            char advance();
            bool match(char expected);
            void addNumber();
            void addIdentifier();
            char peek() const;
            char peekNext() const;
            bool isAlphaNumeric(char c);
    };
}