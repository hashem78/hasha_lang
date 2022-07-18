//
// Created by mythi on 13/07/22.
//

#include "Parser.h"

#include <memory>
#include "magic_enum.hpp"

namespace hasha {

    const std::deque<std::unique_ptr<Token>> *Parser::get_tokens() const {
        return m_parsed_tokens.get();
    }

    void Parser::parse(const std::shared_ptr<std::deque<Lexeme>> &lexemes) {
        m_lexemes = lexemes;
        next_token();
        while (!done()) {
            parse_function();
        }
    }


    bool Parser::next_token() {
        if (done()) return false;

        current_lexeme = m_lexemes->at(cursor++);

        return true;
    }

    bool Parser::accept(const LexType &type) {

        if (current_lexeme.get_type() == type) {
            next_token();
            return true;
        }

        return false;
    }

    bool Parser::expect(const LexType &type) {

        if (accept(type))
            return true;

        fmt::print("Expected {} found {}\n", magic_enum::enum_name(type), current_lexeme.to_string());

        return false;
    }

    bool Parser::done() const {
        return cursor >= m_lexemes->size();
    }

    bool Parser::parse_function() {
        if (accept(LexType::FN_KEYWORD)) {

            auto return_type = current_lexeme.get_data();
            if (!expect(LexType::IDENTIFIER)) return false;

            auto name = current_lexeme.get_data();
            if (!expect(LexType::IDENTIFIER)) return false;

            if (!expect(LexType::LEFT_BRACKET)) return false;

            auto paramsList = parse_function_params();
            if (!paramsList) return false;

            if (!expect(LexType::RIGHT_BRACKET)) return false;

            if (!expect(LexType::LEFT_CURLY)) return false;

            auto parsed_block_token_list = parse_block();

            if (!parsed_block_token_list) return false;

            if (!expect(LexType::RIGHT_CURLY)) return false;

            auto block = Block::create(std::move(parsed_block_token_list));

            auto declaration = FunctionDeclaration::create(
                    return_type, name,
                    std::move(paramsList),
                    std::move(block));
            m_parsed_tokens->push_back(std::move(declaration));
            return true;
        }
        return false;
    }

    Lexeme Parser::peek(int k) const {

        if (k + cursor < m_lexemes->size()) return m_lexemes->at(cursor + k);

        return current_lexeme;
    }

    std::unique_ptr<ParameterList> Parser::parse_function_params() {
        auto paramList = std::make_unique<ParameterList>();
        // if the function has no parameters it should be accepted.
        if (current_lexeme.get_type() == LexType::RIGHT_BRACKET)
            return paramList;

        while (accept(LexType::IDENTIFIER)) {

            if (!expect(LexType::IDENTIFIER)) return nullptr;

            auto type = peek(-3).get_data();
            auto name = peek(-2).get_data();
            paramList->push_back(std::make_unique<FunctionParameter>(type, name));

            // If we've reached the right bracket then this means we
            // read all the parameters.
            if (current_lexeme.get_type() == LexType::RIGHT_BRACKET)
                return paramList;

            if (!expect(LexType::COMMA)) return nullptr;
        }

        return paramList;
    }

    Parser::Parser() : m_parsed_tokens(std::make_unique<TokenList>()) {

    }

    std::unique_ptr<BlockTokenList> Parser::parse_block() {
        auto tokenList = std::make_unique<BlockTokenList>();

        while (auto variable_declaration = parse_variable_declaration()) {
            tokenList->push_back(std::move(variable_declaration));
        }

        return tokenList;
    }

    std::unique_ptr<VariableDeclaration> Parser::parse_variable_declaration() {

        auto type = current_lexeme.get_data();
        if (accept(LexType::IDENTIFIER)) {
            auto name = current_lexeme.get_data();
            if (!expect(LexType::IDENTIFIER)) return nullptr;
            if (!expect(LexType::EQUALS)) return nullptr;
            auto value = current_lexeme.get_data();
            if (!expect(LexType::LITERAL)) return nullptr;

            return std::make_unique<VariableDeclaration>(type, name);
        }
        return nullptr;
    }


} // hasha_lang
