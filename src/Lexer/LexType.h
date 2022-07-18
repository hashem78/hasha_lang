//
// Created by mythi on 13/07/22.
//

#ifndef HASHA_LANG_LEXTYPE_H
#define HASHA_LANG_LEXTYPE_H

enum class LexType {
    LEFT_CURLY,
    RIGHT_CURLY,
    LEFT_BRACKET,
    RIGHT_BRACKET,
    LEFT_SQUARE_BRACKET,
    RIGHT_SQUARE_BRACKET,
    COMMA,
    FN_KEYWORD,
    RETURN_KEYWORD,
    EQUALS,
    PLUS,
    MINUS,
    ASTERISK,
    GREATER_THAN,
    LESS_THAN,
    EXCLAMATION,
    AMPERSAND,
    CARET,
    TILDE,
    DOT,
    PIPE,
    FORWARD_SLASH,
    PERCENT,
    LITERAL,
    IDENTIFIER,
    ILLEGAL,
};

#endif //HASHA_LANG_LEXTYPE_H