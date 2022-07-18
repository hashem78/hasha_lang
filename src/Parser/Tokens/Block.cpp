//
// Created by mythi on 18/07/22.
//

#include "Block.h"

namespace hasha {
    Block::Block(std::unique_ptr<BlockTokenList> tokens) : m_tokens(std::move(tokens)), Token("Block") {

    }

    std::unique_ptr<Block> Block::create(std::unique_ptr<BlockTokenList> tokens) {
        return std::unique_ptr<Block>(new Block(std::move(tokens)));
    }

    const std::unique_ptr<BlockTokenList> &Block::get_tokens() const {
        return m_tokens;
    }

    std::string Block::to_string() const {
        std::string rep;
        for (const auto &token: *m_tokens) {
            rep = fmt::format("{}\n{}", rep, token->to_string());
        }
        return rep;
    }

    nlohmann::json Block::to_json() const {
        auto json = Token::to_json();
        json["tokens"] = nlohmann::json::array();

        for (const auto &token: *m_tokens) {
            json["tokens"].push_back(token->to_json());
        }
        return json;
    }
} // hasha