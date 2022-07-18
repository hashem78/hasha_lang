//
// Created by mythi on 18/07/22.
//

#include "LiteralExpression.h"

namespace hasha {


    LiteralExpression::LiteralExpression(std::string literal) :
            m_literal(std::move(literal)),
            Expression("LiteralExpression") {

    }

    std::string_view LiteralExpression::get_literal() const {
        return m_literal;
    }

    std::string LiteralExpression::to_string() const {
        return fmt::format("literal: {}", m_literal);
    }

    nlohmann::json LiteralExpression::to_json() const {
        auto json = Token::to_json();
        json["literal"] = m_literal;

        return json;
    }
} // hasha