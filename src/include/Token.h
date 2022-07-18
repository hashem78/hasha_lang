//
// Created by mythi on 13/07/22.
//

#ifndef HASHA_LANG_TOKEN_H
#define HASHA_LANG_TOKEN_H


#include <list>
#include <memory>
#include <utility>

#include "fmt/format.h"
#include "nlohmann/json.hpp"

namespace hasha {
    class FunctionParameter;

    class Token;

    using ParameterList = std::vector<std::unique_ptr<FunctionParameter>>;
    using BlockTokenList = std::list<std::unique_ptr<Token>>;

    // Parser Token
    class Token {
        static int id_counter;
        const int m_id;
        const std::string m_token_type;
    public:
        explicit Token(std::string token_type) : m_token_type(std::move(token_type)), m_id(id_counter++) {

        }

        [[nodiscard]]
        int get_id() const {
            return m_id;
        }

        [[nodiscard]]
        virtual std::string to_string() const = 0;

        [[nodiscard]]
        virtual nlohmann::json to_json() const {
            return {
                    {"id",         m_id},
                    {"token_type", m_token_type}
            };
        };

        virtual ~Token() = default;

    };


    class Block : public Token {

        const std::unique_ptr<BlockTokenList> m_tokens;

        explicit Block(std::unique_ptr<BlockTokenList> tokens) : m_tokens(std::move(tokens)), Token("Block") {

        }

    public:

        static std::unique_ptr<Block> create(std::unique_ptr<BlockTokenList> tokens) {
            return std::unique_ptr<Block>(new Block(std::move(tokens)));
        }

        [[nodiscard]]
        const std::unique_ptr<BlockTokenList> &get_tokens() const {
            return m_tokens;
        }


        [[nodiscard]]
        std::string to_string() const override {
            std::string rep;
            for (const auto &token: *m_tokens) {
                rep = fmt::format("{}\n{}", rep, token->to_string());
            }
            return rep;
        }

        [[nodiscard]]
        nlohmann::json to_json() const override {
            auto json = Token::to_json();
            json["tokens"] = nlohmann::json::array();

            for (const auto &token: *m_tokens) {
                json["tokens"].push_back(token->to_json());
            }
            return json;
        }
    };

    class FunctionParameter : public Token {
        const std::string m_type;
        const std::string m_name;

    public:

        FunctionParameter(std::string type, std::string name) : m_type(std::move(type)), m_name(std::move(name)),
                                                                Token("FunctionParameter") {

        }

        [[nodiscard]]
        std::string_view get_type() const {
            return m_type;
        }

        [[nodiscard]]
        std::string_view get_name() const {
            return m_name;
        }

        [[nodiscard]]
        std::string to_string() const override {
            return fmt::format("type: {}, name: {}", m_type, m_name);
        }

        [[nodiscard]]
        nlohmann::json to_json() const override {
            auto json = Token::to_json();

            json["type"] = m_type;
            json["name"] = m_name;

            return json;
        }
    };

    class FunctionDeclaration : public Token {
        const std::string m_return_type;
        const std::string m_name;

        std::unique_ptr<ParameterList> m_parameters;
        std::unique_ptr<Block> m_block;


        FunctionDeclaration
                (std::string return_type,
                 std::string name,
                 std::unique_ptr<ParameterList> parameters,
                 std::unique_ptr<Block> block) :
                m_return_type(std::move(return_type)),
                m_name(std::move(name)),
                m_parameters(std::move(parameters)),
                m_block(std::move(block)),Token("FunctionDeclaration") {
        }

    public:


        static std::unique_ptr<Token> create(
                std::string return_type,
                std::string name,
                std::unique_ptr<ParameterList> parameters,
                std::unique_ptr<Block> block

        ) {
            return std::unique_ptr<FunctionDeclaration>(
                    new FunctionDeclaration(
                            std::move(return_type),
                            std::move(name),
                            std::move(parameters),
                            std::move(block)));
        }


        [[nodiscard]]
        std::string to_string() const override {
            std::string rep;
            for (const auto &parameter: *m_parameters) {
                rep = fmt::format("{}\n{}", rep, parameter->to_string());
            }
            return rep;
        }

        [[nodiscard]]
        nlohmann::json to_json() const override {
            auto json = Token::to_json();

            json["name"] = m_name;
            json["return_type"] = m_return_type;
            json["block"] = m_block->to_json();
            json["parameters"] = nlohmann::json::array();

            for (const auto &token: *m_parameters) {
                json["parameters"].push_back(token->to_json());
            }
            return json;
        }
    };


    class VariableDeclaration : public Token {
        const std::string m_type;
        const std::string m_name;

    public:

        VariableDeclaration(std::string type, std::string name
        ) : m_type(std::move(type)), m_name(std::move(name)),Token("VariableDeclaration") {

        }

        [[nodiscard]]
        std::string_view get_type() const {
            return m_type;
        }

        [[nodiscard]]
        std::string_view get_name() const {
            return m_name;
        }

        [[nodiscard]]
        std::string to_string() const override {
            return fmt::format("type: {}, name: {}", m_type, m_name);
        }

        [[nodiscard]]
        nlohmann::json to_json() const override {
            auto json = Token::to_json();

            json["type"] = m_type;
            json["name"] = m_name;

            return json;
        }
    };


} // hasha

#endif //HASHA_LANG_TOKEN_H
