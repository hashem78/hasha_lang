#include "Lexer.h"
#include <fstream>
#include "Parser.h"
#include "fmt/format.h"

int main(int argc, char **argv) {
    hasha::Lexer lexer;
    std::ifstream file("source.hasha");
    std::string line;

    while (std::getline(file, line)) {
        lexer.lex(line);
    }

    for (const auto &lexeme: lexer.get_lexemes()) {
        fmt::print("{}\n", lexeme.to_string());
    }
}
