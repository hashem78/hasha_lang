//
// Created by mythi on 13/07/22.
//

#include "Parser.h"

namespace hasha {
    std::list<Token> hasha::Parser::parse() {
        // TODO: Parse Lexeme
    }

    const std::list<Lexeme> &Parser::get_lexemes() const {
        return lexemes;
    }

    Parser::Parser(const std::list<Lexeme> &lexemes) : lexemes(lexemes) {}

} // hasha_lang
