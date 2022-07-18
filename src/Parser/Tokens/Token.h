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

    class Token {
        static int token_counter;
        const int m_id;
        const std::string m_token_type;
    public:
        explicit Token(std::string token_type);

        [[nodiscard]]
        int get_id() const;

        [[nodiscard]]
        virtual std::string to_string() const = 0;

        [[nodiscard]]
        virtual nlohmann::json to_json() const;

        virtual ~Token() = default;

        Token(const Token &) = delete;
    };






} // hasha

#endif //HASHA_LANG_TOKEN_H
