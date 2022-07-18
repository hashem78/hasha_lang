//
// Created by mythi on 13/07/22.
//

#ifndef HASHA_LANG_PARSER_H
#define HASHA_LANG_PARSER_H

#include <string>
#include <deque>
#include <memory>

#include "fmt/format.h"
#include "Lexeme.h"
#include "utils.h"
#include "Token.h"
#include "Lexer.h"
#include "LiteralExpression.h"
#include "FunctionParameter.h"
#include "FunctionDeclaration.h"
#include "VariableDeclaration.h"

namespace hasha {

    class Parser {
        using TokenList = std::deque<std::unique_ptr<Token>>;
        using LexemeList = std::deque<Lexeme>;

        std::unique_ptr<TokenList> m_parsed_tokens;
        std::shared_ptr<LexemeList> m_lexemes;

        int cursor = 0;

        Lexeme current_lexeme;

        bool next_token();

        [[nodiscard]]
        bool done() const;

        bool accept(const LexType &);

        bool expect(const LexType &);

        [[nodiscard]]
        Lexeme peek(int k = 1) const;

        bool parse_function();

        std::unique_ptr<ParameterList> parse_function_params();

        std::unique_ptr<BlockTokenList> parse_block();

        std::unique_ptr<VariableDeclaration> parse_variable_declaration();

        std::unique_ptr<Expression> parse_expression();
        std::unique_ptr<LiteralExpression> parse_literal_expression();


    public:
        Parser();

        void parse(const std::shared_ptr<std::deque<Lexeme>> &lexemes);


        [[nodiscard]]
        const std::deque<std::unique_ptr<Token>> *get_tokens() const;



    };

} // hasha_lang

#endif //HASHA_LANG_PARSER_H
