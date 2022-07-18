//
// Created by mythi on 18/07/22.
//

#ifndef HASHA_LANG_VARIABLEDECLARATION_H
#define HASHA_LANG_VARIABLEDECLARATION_H
#include "Token.h"
namespace hasha {

    class VariableDeclaration : public Token {
        const std::string m_type;
        const std::string m_name;

    public:

        VariableDeclaration(std::string type, std::string name
        );

        [[nodiscard]]
        std::string_view get_type() const;

        [[nodiscard]]
        std::string_view get_name() const;

        [[nodiscard]]
        std::string to_string() const override;

        [[nodiscard]]
        nlohmann::json to_json() const override;
    };

}


#endif //HASHA_LANG_VARIABLEDECLARATION_H
