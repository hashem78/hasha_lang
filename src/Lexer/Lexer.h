//
// Created by mythi on 13/07/22.
//

#ifndef HASHA_LANG_LEXER_H
#define HASHA_LANG_LEXER_H

#include <string>
#include <fstream>
#include <iomanip>
#include <chrono>
#include <deque>
#include "date/date.h"
#include "fmt/format.h"
#include "Lexeme.h"
#include "../Parser/utils.h"
#include "nlohmann/json.hpp"

namespace hasha {

    class Lexer {

        int cursor = 0;

        std::string_view m_line;

        std::shared_ptr<std::deque<Lexeme>> lexemes;

        inline bool done();

        static inline bool is_identifier(std::string_view);

        static inline bool is_literal(std::string_view);

        static inline bool is_legal(char);

        std::string consume_special();

        std::string consume_illegal();

        std::string consume();

        void skip_spaces();


    public:

        void lex();

        void set_line(std::string_view line);

        [[nodiscard]]
        std::shared_ptr<std::deque<Lexeme>> get_lexemes() const;

        Lexer();

        static void dump_lexemes_as_json(const std::deque<Lexeme> &lexemes);
    };

} // hasha

#endif //HASHA_LANG_LEXER_H
