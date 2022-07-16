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
        src/include/Token.h)

target_link_libraries(hasha_lang
        fmt::fmt-header-only
        magic_enum::magic_enum
        nlohmann_json::nlohmann_json
        date::date)

