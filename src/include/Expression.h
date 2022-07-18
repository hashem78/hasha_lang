//
// Created by mythi on 18/07/22.
//

#ifndef HASHA_LANG_EXPRESSION_H
#define HASHA_LANG_EXPRESSION_H

#include "Token.h"

namespace hasha {

    class Expression : public Token {
    public:
        explicit Expression(std::string expression_type);

        Expression(const Expression &) = delete;
    };

} // hasha

#endif //HASHA_LANG_EXPRESSION_H
