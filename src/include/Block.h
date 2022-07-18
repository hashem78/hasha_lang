//
// Created by mythi on 18/07/22.
//

#ifndef HASHA_LANG_BLOCK_H
#define HASHA_LANG_BLOCK_H

#include "Token.h"
namespace hasha {
    using BlockTokenList = std::list<std::unique_ptr<Token>>;

    class Block : public Token {

        const std::unique_ptr<BlockTokenList> m_tokens;

        explicit Block(std::unique_ptr<BlockTokenList> tokens);

    public:

        static std::unique_ptr<Block> create(std::unique_ptr<BlockTokenList> tokens);

        [[nodiscard]]
        const std::unique_ptr<BlockTokenList> &get_tokens() const;


        [[nodiscard]]
        std::string to_string() const override;

        [[nodiscard]]
        nlohmann::json to_json() const override;

        Block(const Block &) = delete;
    };


} // hasha

#endif //HASHA_LANG_BLOCK_H
