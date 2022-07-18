#include "Lexer/Lexer.h"
#include "Parser/Parser.h"
#include <fstream>
#include <iostream>
#include "fmt/format.h"

int main(int argc, char **argv) {
    auto lexer = hasha::Lexer();
    std::ifstream file("source.hasha");
    std::string line;

    while (std::getline(file, line)) {
        lexer.set_line(line);
        lexer.lex();
    }

    for (const auto &lexeme: *lexer.get_lexemes()) {
        fmt::print("{}\n", lexeme.to_string());
    }

    auto parser = hasha::Parser();
    parser.parse(lexer.get_lexemes());

    auto parsed_tokens = parser.get_tokens();

    for (const auto &token: *parsed_tokens) {
        std::cout << std::setw(4) << token->to_json() << std::endl;
    }

}
