//
// Created by mythi on 13/07/22.
//

#include "Lexer.h"


namespace hasha {
    void Lexer::lex(std::string_view line) {
        this->to_lex = line;

        std::string token;
        while (!done() || !token.empty()) {
            if (token == "fn") {
                lexemes.emplace_back(LexType::FN_KEYWORD, "fn");
                token.clear();
            } else if (token == "(") {
                lexemes.emplace_back(LexType::LEFT_BRACKET, "(");
                token.clear();
            } else if (token == ")") {
                lexemes.emplace_back(LexType::RIGHT_BRACKET, ")");
                token.clear();
            } else if (token == "{") {
                lexemes.emplace_back(LexType::LEFT_CURLY, "{");
                token.clear();
            } else if (token == "}") {
                lexemes.emplace_back(LexType::RIGHT_CURLY, "}");
                token.clear();
            } else if (token == "[") {
                lexemes.emplace_back(LexType::LEFT_SQUARE_BRACKET, "[");
                token.clear();
            } else if (token == "]") {
                lexemes.emplace_back(LexType::RIGHT_SQUARE_BRACKET, "]");
                token.clear();
            } else if (token == ",") {
                lexemes.emplace_back(LexType::COMMA, ",");
                token.clear();
            } else if (token == "=") {
                lexemes.emplace_back(LexType::EQUALS, "=");
                token.clear();
            } else if (token == "+") {
                lexemes.emplace_back(LexType::PLUS, "+");
                token.clear();
            } else if (token == "-") {
                lexemes.emplace_back(LexType::MINUS, "-");
                token.clear();
            } else if (token == "*") {
                lexemes.emplace_back(LexType::ASTERISK, "*");
                token.clear();
            } else if (token == ">") {
                lexemes.emplace_back(LexType::GREATER_THAN, ">");
                token.clear();
            } else if (token == "<") {
                lexemes.emplace_back(LexType::LESS_THAN, "<");
                token.clear();
            } else if (token == "!") {
                lexemes.emplace_back(LexType::EXCLAMATION, "!");
                token.clear();
            } else if (token == "&") {
                lexemes.emplace_back(LexType::AMPERSAND, "&");
                token.clear();
            } else if (token == "^") {
                lexemes.emplace_back(LexType::CARET, "^");
                token.clear();
            } else if (token == "~") {
                lexemes.emplace_back(LexType::TILDE, "~");
                token.clear();
            } else if (token == ".") {
                lexemes.emplace_back(LexType::DOT, ".");
                token.clear();
            } else if (token == "|") {
                lexemes.emplace_back(LexType::PIPE, "|");
                token.clear();
            } else if (token == "/") {
                lexemes.emplace_back(LexType::FORWARD_SLASH, "/");
                token.clear();
            } else if (token == "%") {
                lexemes.emplace_back(LexType::PERCENT, "%");
                token.clear();
            } else if (is_literal(token)) {
                lexemes.emplace_back(LexType::LITERAL, token);
                token.clear();
            } else if (is_identifier(token)) {
                lexemes.emplace_back(LexType::IDENTIFIER, token);
                token.clear();
            } else if (!token.empty()) {
                lexemes.emplace_back(LexType::ILLEGAL, token);
                token.clear();
            }

            skip_spaces();
            token += consume();
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }

        cursor = 0;
    }

    const std::list<Lexeme> &Lexer::get_lexemes() const {
        return lexemes;
    }

    Lexer::Lexer() : parser(lexemes) {

    }

    bool Lexer::done() {
        return cursor >= to_lex.length();
    }

    bool Lexer::is_identifier(std::string_view str) {
        if (str.empty())
            return false;
        for (auto ch: str)
            if (!std::isalnum(ch) && ch != '_') return false;
        return true;
    }

    bool Lexer::is_literal(std::string_view str) {
        if (str.empty())
            return false;
        for (auto ch: str)
            if (!std::isdigit(ch)) return false;
        return true;
    }

    bool Lexer::is_legal(char c) {
        auto special = std::string("{}[]()=+-*/%,<>!&^~.|");
        for (auto ch: special)
            if (ch == c)
                return true;
        return false;
    }

    std::string Lexer::consume_special() {
        auto token = std::string();

        auto curr = to_lex[cursor];
        if (is_legal(curr) && !done()) {
            token += curr;
            cursor++;
        }
        return token;
    }

    std::string Lexer::consume_illegal() {
        auto token = std::string();

        auto curr = to_lex[cursor];
        if (!is_legal(curr) && !done()) {
            token += curr;
            cursor++;
        }
        return token;
    }

    std::string Lexer::consume() {
        auto token = std::string();

        while (!done()) {
            auto curr = to_lex[cursor];

            auto is_alpha_numeric = std::isalnum(curr);
            auto is_underscore = curr == '_';

            if (is_alpha_numeric || is_underscore) {
                token += to_lex[cursor];
                cursor++;
            } else {
                break;
            }

        }
        if (token.empty()) {
            token += consume_special();
        }
        if (token.empty()) {
            token += consume_illegal();
        }
        return token;
    }

    void Lexer::skip_spaces() {
        while (std::isspace(to_lex[cursor]) && !done())
            cursor++;
    }

    void Lexer::dump_lexemes_as_json() {
        auto lexemes_json = nlohmann::json::array();
        for (const auto &lexeme: lexemes) {
            auto lexeme_json = nlohmann::json();
            lexeme_json["type"] = lexeme.get_type_as_string();
            lexeme_json["data"] = lexeme.get_data();
            lexemes_json.push_back(lexeme_json);
        }
        auto get_current_time_and_date = [] {
            auto now = std::chrono::system_clock::now();
            auto day_point = date::floor<date::days>(now);
            auto ymd = date::year_month_day{day_point};
            auto time = date::make_time(now - day_point);
            std::stringstream ss;
            ss << ymd.day() << "-" << ymd.month() << "-" << ymd.year() << "-" << now.time_since_epoch().count();
            return ss.str();
        };
        auto file_name = fmt::format("lexer_output_{}.json", get_current_time_and_date());
        std::ofstream file(file_name);
        file << std::setw(4) << lexemes_json;
    }


} //hasha