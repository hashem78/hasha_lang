//
// Created by mythi on 13/07/22.
//

#ifndef HASHA_LANG_LEXEME_H
#define HASHA_LANG_LEXEME_H

#include <string>
#include <compare>
#include "LexType.h"

namespace hasha {

    class Lexeme {

        LexType m_type;
        std::string m_lex_data;

    public:
        Lexeme();

        Lexeme(LexType type, std::string lexeme_data);

        auto operator<=>(const Lexeme &rhs) const = default;

        [[nodiscard]] LexType get_type() const;

        [[nodiscard]] std::string get_data() const;

        [[nodiscard]] std::string get_type_as_string() const;

        [[nodiscard]] std::string get_data_as_string() const;

        [[nodiscard]] std::string to_string() const;

    };


} // hasha

#endif //HASHA_LANG_LEXEME_H
