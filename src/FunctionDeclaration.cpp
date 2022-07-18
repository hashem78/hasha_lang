//
// Created by mythi on 18/07/22.
//
#include "FunctionDeclaration.h"
#include "Expression.h"

namespace hasha {

    FunctionDeclaration::FunctionDeclaration(
            std::string return_type, std::string name,
            std::unique_ptr<ParameterList> parameters, std::unique_ptr<Block> block,
            std::unique_ptr<Expression> return_expression) :

            m_return_type(std::move(return_type)),
            m_name(std::move(name)),
            m_parameters(std::move(parameters)),
            m_block(std::move(block)),
            m_return_expression(std::move(return_expression)),

            Expression("FunctionDeclaration") {
    }

    std::unique_ptr<Expression>
    FunctionDeclaration::create(
            std::string return_type,
            std::string name,
            std::unique_ptr<ParameterList> parameters,
            std::unique_ptr<Block> block,
            std::unique_ptr<Expression> return_expression) {
        return std::unique_ptr<FunctionDeclaration>(
                new FunctionDeclaration(
                        std::move(return_type),
                        std::move(name),
                        std::move(parameters),
                        std::move(block),
                        std::move(return_expression)
                )
        );
    }

    std::string FunctionDeclaration::to_string() const {
        std::string rep;
        for (const auto &parameter: *m_parameters) {
            rep = fmt::format("{}\n{}", rep, parameter->to_string());
        }
        return rep;
    }

    nlohmann::json FunctionDeclaration::to_json() const {
        auto json = Token::to_json();

        json["name"] = m_name;
        json["return_type"] = m_return_type;
        json["return_expression"] = m_return_expression->to_json();
        json["block"] = m_block->to_json();

        json["parameters"] = nlohmann::json::array();

        for (const auto &token: *m_parameters) {
            json["parameters"].push_back(token->to_json());
        }
        return json;
    }
}