#pragma once

#include <vector>
#include "Token.h"
namespace hasi
{
    class Scanner 
    {
        public:
            Scanner(const char* source, uint32_t size) :
                _source(source), _inputLength(size) {}
            void scan();
            std::vector<Token>& getTokens() { return _tokens; }
        private:
            const char* _source;
            std::vector<Token> _tokens;

            uint32_t _start = 0;
            uint32_t _current = 0;
            uint32_t _inputLength = 0;

            bool isAtEnd();
            void scanToken();
            void addToken(TokenType type, TokenValue value);
            char advance();
    };
}