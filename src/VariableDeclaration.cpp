//
// Created by mythi on 18/07/22.
//

#include "VariableDeclaration.h"

namespace hasha {

    VariableDeclaration::VariableDeclaration(std::string type, std::string name) :
            m_type(std::move(type)),
            m_name(std::move(name)),
            Token("VariableDeclaration") {

    }

    std::string_view VariableDeclaration::get_type() const {
        return m_type;
    }

    std::string_view VariableDeclaration::get_name() const {
        return m_name;
    }

    std::string VariableDeclaration::to_string() const {
        return fmt::format("type: {}, name: {}", m_type, m_name);
    }

    nlohmann::json VariableDeclaration::to_json() const {
        auto json = Token::to_json();

        json["type"] = m_type;
        json["name"] = m_name;

        return json;
    }
}