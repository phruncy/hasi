# hasi_spec

## expressions

## Data Types

The only data type in Hasi are 32-bit floating point numbers.

### Thruthiness and falseness

- Only the literal "0" is treated as falsy. Any other number value is treated as truthy

## reserved keywords

???

## identifier names

- any sequence of allowed characters that is not a reserved keyword

- allowed characters: alphanumeric characters and the character '_'
- the first character must not be a digit

## Operators

- hasi has the following operators:
- - binary: +, - , * , /
- - unary: -

### Operator precedence

From highest to lowest

- parenthesized expressions: (<expression>)
- function calls 
- multiplicatives: x * y, x / y
- additives: x + y, x - y

#### Multiplication operator '*'
#### Division operator '/'

- division by the literal "0" results in a compile time error;

#### Modulo operator '%'


## Builtin Functions

- noise: 
- min, max, clamp


## Lexical grammar

FILE : (TOKEN)* 'EOF'
TOKEN : 
    LEFT_PAREN, = '('
    RIGHT_PAREN = ')' |

    PLUS = '+' |
    MINUS = '-'|
    STAR = '*'|
    SLASH = '/'|
    PERCENT = '%'|

    EQUAL = '='|
    EQUAL_EQUAL = '=='|
    GREATER = '>'|
    GREATER_EQUAL = '>='|
    LESS = '<'|
    LESS_EQUAL = '<='|
    BANG = '!'|
    BANG_EQUAL = '!='|

    COND_OR = 'or'|
    COND_AND = 'and'|

    QUESTION = '?'|
    COLON = ':'|
    COMMA = ','

    NUMBER,
    IDENTIFIER
IDENTIFIER : ('_'alpha | alpha)(alphanumerical)*

## Syntactic Grammar

top_level_expr  : additive
expression      : assignment
assignment      : (IDENTIFIER EQUAL assignment) | conditional
conditional     : conditional_or (QUESTION expression COLON expression)?
conditional_or  : conditional_and (COND_OR conditional_and)*
conditional_and : equality (COND_AND equality)*
equality        : comparison ((EQUAL_EQUAL | BANG_EQUAL) comparison)*
comparison      : additive ((GREATER | GREATER_EQUAL | LESS | LESS_EQUAL) additive)*
additive        : factor ((PLUS | MINUS) factor)*
factor          : unary ((STAR | SLASH) unary)*
unary           : ((MINUS | BANG) unary) | call
call            : primary | ('floor'|'ceil') PAREN_LEFT expression PAREN_RIGHT | ('min'|'max') PARENL_LEFT primary COMMA additive PAREN_RIGHT
primary         : 
    NUMBER | 
    IDENTIFIER | 
    (PAREN_LEFT expression PAREN_RIGHT)