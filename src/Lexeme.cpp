//
// Created by mythi on 13/07/22.
//

#include "Lexeme.h"

#include <utility>
#include "magic_enum.hpp"
#include "fmt/format.h"

namespace hasha {


    Lexeme::Lexeme() {
        m_type = LexType::ILLEGAL;
    }

    Lexeme::Lexeme(LexType type, std::string lexeme_data) {
        m_type = type;
        m_lex_data = std::move(lexeme_data);
    }

    std::string Lexeme::get_data() const {
        return m_lex_data;
    }

    std::string Lexeme::get_type_as_string() const {
        return std::string(magic_enum::enum_name(m_type));
    }

    std::string Lexeme::to_string() const {
        return fmt::format("{} {}", get_type_as_string(), m_lex_data);
    }

} // hasha