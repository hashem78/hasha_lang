//
// Created by mythi on 18/07/22.
//

#include "Token.h"

namespace hasha {
    int Token::token_counter = 0;

    Token::Token(std::string token_type) : m_token_type(std::move(token_type)), m_id(token_counter++) {

    }

    int Token::get_id() const {
        return m_id;
    }

    nlohmann::json Token::to_json() const {
        return {
                {"id",         m_id},
                {"token_type", m_token_type}
        };
    }
}