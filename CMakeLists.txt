cmake_minimum_required(VERSION 3.22)
project(hasha_lang)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(libs/fmt)
add_subdirectory(libs/magic_enum)
add_subdirectory(libs/json)
add_subdirectory(libs/date)

include_directories(hasha_lang src/Parser/include)
add_executable(hasha_lang
        src/main.cpp
        src/Lexer/Lexer.cpp
        src/Lexer/Lexer.h
        src/Lexer/Lexeme.cpp
        src/Lexer/Lexeme.h
        src/Lexer/LexType.h
        src/Parser/utils.h
        src/Parser/Parser.cpp
        src/Parser/Parser.h
        src/Parser/Tokens/Token.h
        src/Parser/Tokens/Token.cpp
        src/Parser/Tokens/Block.cpp
        src/Parser/Tokens/Block.h
        src/Parser/Tokens/FunctionParameter.h
        src/Parser/Tokens/FunctionParameter.cpp
        src/Parser/Tokens/FunctionParameter.h
        src/Parser/Tokens/FunctionDeclaration.cpp
        src/Parser/Tokens/FunctionDeclaration.h
        src/Parser/Tokens/VariableDeclaration.cpp src/Parser/Tokens/VariableDeclaration.h src/Parser/Tokens/Expressions/Expression.cpp src/Parser/Tokens/Expressions/Expression.h src/Parser/Tokens/Expressions/LiteralExpression.cpp src/Parser/Tokens/Expressions/LiteralExpression.h)

target_link_libraries(hasha_lang
        fmt::fmt-header-only
        magic_enum::magic_enum
        nlohmann_json::nlohmann_json
        date::date)

add_compile_options(-fsanitize=address)
add_link_options(-fsanitize=address)