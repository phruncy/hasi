#include "Scanner.h"
#include "hasi_error.h"
#include "keywords.h"

using std::string;

namespace hasi
{
    void Scanner::scan()
    {
        _tokens = std::vector<Token>();
        while (!isAtEnd())
        {
            _start = _current;
            scanToken();
        }
    }

    bool Scanner::isAtEnd()
    {
        return _current >= _source.size();
    }
    
    void Scanner::scanToken()
    {
        char c = advance();
        switch(c)
        {
            case '+':
                addToken(TokenType::PLUS, HASI_NOVALUE);
                break;
            case '-':
                addToken(TokenType::MINUS, HASI_NOVALUE);
                break;
            case '*':
                addToken(TokenType::STAR, HASI_NOVALUE);
                break;
            case '/':
                addToken(TokenType::SLASH, HASI_NOVALUE);
                break;
            case '(':
                addToken(TokenType::LEFT_PAREN, HASI_NOVALUE);
                break;
            case ')':
                addToken(TokenType::RIGHT_PAREN, HASI_NOVALUE);
                break;
            case '=':
                addToken(match('=') ? TokenType::EQUAL_EQUAL : TokenType::EQUAL, HASI_NOVALUE);
                break;
            case '>':
                addToken(match('=') ? TokenType::GREATER_EQUAL : TokenType::GREATER, HASI_NOVALUE);
                break;
            case '<':
                addToken(match('=') ? TokenType::LESS_EQUAL : TokenType::LESS, HASI_NOVALUE);
                break;
            case '!':
                addToken(match('=') ? TokenType::BANG_EQUAL : TokenType::BANG, HASI_NOVALUE);
                break;

            // ignore these characters
            case ' ':
            case '\r':
            case '\n':
                break;
            //identifiers
            default:
                if(isdigit(c)) addNumber();
                if(isalpha(c)) addIdentifier();
                else 
                {
                    string message = "Unexpected token " + c;
                    hasi_error::report("Scanner", message);
                    _hadError = true;
                }
                break;
        }

    }

    char Scanner::advance()
    {
        return _source[++_current];
    }

    bool Scanner::match(char expected)
    {
        if (isAtEnd())
            return false;
        if (_source.at(_current) != expected)
            return false;
        _current++;
        return true;
    }

    void Scanner::addToken(TokenType type, TokenValue value)
    {
        string lexeme = _source.substr(_start, _current);
        _tokens.emplace_back(type, lexeme, value);
    }

    void Scanner::addNumber()
    {
        while(isdigit(peek()))
        {
            advance();
        }
        if(peek() == '.' and isdigit(peekNext()))
        {
            advance();
            while(isdigit(peek()))
            {
                advance();
            }
        }
        addToken(TokenType::NUMBER, std::stof(_source.substr(_start, _current)));
    }

    void Scanner::addIdentifier()
    {
        while(isAlphaNumeric(peek()))
        {
            advance();
        }
        string lexeme = _source.substr(_start, _current);
        TokenType type = 0;
        addToken(type, lexeme);
    }

    char Scanner::peek()
    {
        if(isAtEnd())
            return '\0';
        return _source.at(_current);
    }

    char Scanner::peekNext()
    {
        if(_current + 1 >= _source.size())
        {
            return '\0';
        }
        else 
        {
            return _source.at(_current + 1);
        }
    }

    bool isAlpha(char c)
    {
        return 
        (
            c>= 'a' && c <= 'z' ||
            c >= 'A' && c <= 'Z' ||
            c == '_'
        );
    }
    bool Scanner::isAlphaNumeric(char c)
    {
        return isAlpha(c) || isdigit(c);
    }
}