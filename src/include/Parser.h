//
// Created by mythi on 13/07/22.
//

#ifndef HASHA_LANG_PARSER_H
#define HASHA_LANG_PARSER_H

#include <string>
#include <functional>
#include <thread>
#include <list>
#include <condition_variable>
#include <functional>
#include <sstream>
#include <algorithm>
#include "fmt/format.h"

#include "Lexeme.h"
#include "utils.h"
#include "Token.h"

namespace hasha {

    class Parser {
        const std::list<Lexeme> &lexemes;
    public:
        Parser(const std::list<Lexeme> &lexemes);

        std::list<Token> parse();

        [[nodiscard]]
        const std::list<Lexeme> &get_lexemes() const;
    };

} // hasha_lang

#endif //HASHA_LANG_PARSER_H
