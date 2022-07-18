//
// Created by mythi on 18/07/22.
//

#ifndef HASHA_LANG_FUNCTIONDECLARATION_H
#define HASHA_LANG_FUNCTIONDECLARATION_H

#include "Token.h"
#include "Block.h"
#include "Expression.h"
#include "FunctionParameter.h"

namespace hasha {
    class FunctionDeclaration : public Expression {

        const std::string m_return_type;
        const std::string m_name;

        const std::unique_ptr<Token> m_return_expression;

        std::unique_ptr<ParameterList> m_parameters;
        std::unique_ptr<Block> m_block;


        FunctionDeclaration
                (std::string return_type,
                 std::string name,
                 std::unique_ptr<ParameterList> parameters,
                 std::unique_ptr<Block> block,
                 std::unique_ptr<Expression> return_expression
                );

    public:


        static std::unique_ptr<Expression> create(
                std::string return_type,
                std::string name,
                std::unique_ptr<ParameterList> parameters,
                std::unique_ptr<Block> block,
                std::unique_ptr<Expression> return_expression

        );


        [[nodiscard]]
        std::string to_string() const override;

        [[nodiscard]]
        nlohmann::json to_json() const override;

        FunctionDeclaration(const FunctionDeclaration &) = delete;
    };
}

#endif //HASHA_LANG_FUNCTIONDECLARATION_H
