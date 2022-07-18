//
// Created by mythi on 18/07/22.
//

#ifndef HASHA_LANG_LITERALEXPRESSION_H
#define HASHA_LANG_LITERALEXPRESSION_H

#include "Expression.h"

namespace hasha {

    class LiteralExpression : public Expression {
        const std::string m_literal;

    public:
        explicit LiteralExpression(std::string literal);

        [[nodiscard]]
        std::string_view get_literal() const;

        [[nodiscard]]
        std::string to_string() const override;

        [[nodiscard]]
        nlohmann::json to_json() const override;

        LiteralExpression(const LiteralExpression &) = delete;

    };

} // hasha

#endif //HASHA_LANG_LITERALEXPRESSION_H
