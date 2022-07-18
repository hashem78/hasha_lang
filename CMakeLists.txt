cmake_minimum_required(VERSION 3.22)
project(hasha_lang)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(libs/fmt)
add_subdirectory(libs/magic_enum)
add_subdirectory(libs/json)
add_subdirectory(libs/date)

include_directories(hasha_lang src/include)
add_executable(hasha_lang
        main.cpp
        src/Lexer.cpp
        src/include/Lexer.h
        src/Lexeme.cpp
        src/include/Lexeme.h
        src/include/LexType.h
        src/include/utils.h
        src/Parser.cpp
        src/include/Parser.h
        src/include/Token.h
        src/Token.cpp
        src/Block.cpp
        src/include/Block.h
        src/include/FunctionParameter.h
        src/FunctionParameter.cpp
        src/include/FunctionParameter.h
        src/FunctionDeclaration.cpp
        src/include/FunctionDeclaration.h
        src/VariableDeclaration.cpp src/include/VariableDeclaration.h src/Expression.cpp src/include/Expression.h src/LiteralExpression.cpp src/include/LiteralExpression.h)

target_link_libraries(hasha_lang
        fmt::fmt-header-only
        magic_enum::magic_enum
        nlohmann_json::nlohmann_json
        date::date)

add_compile_options(-fsanitize=address)
add_link_options(-fsanitize=address)