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
    FN_KEYWORD,
    SYMBOL,
    LITERAL,
    IDENTIFIER,
    ILLEGAL,
};

#endif //HASHA_LANG_LEXTYPE_H
