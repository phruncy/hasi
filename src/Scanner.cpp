#include "Scanner.h"

namespace hasi
{
    void Scanner::scan()
    {
        _tokens = std::vector<Token>();
        while (!isAtEnd())
        {
            scanToken();
        }
    }

    bool Scanner::isAtEnd()
    {
        return _current >= _inputLength;
    }
    
    void Scanner::scanToken()
    {
        char c = advance();
        switch(c)
        {
        }

    }
    char Scanner::advance()
    {
        return _source[++_current];
    }
}