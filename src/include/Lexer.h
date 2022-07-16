//
// Created by mythi on 13/07/22.
//

#ifndef HASHA_LANG_LEXER_H
#define HASHA_LANG_LEXER_H

#include <string>
#include <fstream>
#include <iomanip>
#include <chrono>
#include "date/date.h"
#include "fmt/format.h"
#include "Lexeme.h"
#include "Parser.h"
#include "utils.h"
#include "nlohmann/json.hpp"

namespace hasha {

    class Lexer {

        std::list<Lexeme> lexemes;
        Parser parser;
        int cursor = 0;
        std::string_view to_lex;

        inline bool done();

        static inline bool is_identifier(std::string_view);

        static inline bool is_literal(std::string_view);

        static inline bool is_legal(char);

        std::string consume_special();

        std::string consume_illegal();

        std::string consume();


        void skip_spaces();

    public:
        Lexer();

        [[nodiscard]]
        const std::list<Lexeme> &get_lexemes() const;

        void lex(std::string_view);

        void dump_lexemes_as_json();
    };

} // hasha

#endif //HASHA_LANG_LEXER_H
