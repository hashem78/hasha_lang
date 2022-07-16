//
// Created by mythi on 13/07/22.
//

#ifndef HASHA_LANG_UTILS_H
#define HASHA_LANG_UTILS_H

#include <sstream>

namespace utils {

    inline std::string &rtrim(std::string &s, const char *t = " \t\n\r\f\v") {
        s.erase(s.find_last_not_of(t) + 1);
        return s;
    }

    inline std::string &ltrim(std::string &s, const char *t = " \t\n\r\f\v") {
        s.erase(0, s.find_first_not_of(t));
        return s;
    }

    inline std::string &trim(std::string &s, const char *t = " \t\n\r\f\v") {
        return ltrim(rtrim(s, t), t);
    }

    inline void skip_spaces(std::stringstream &stream) {
        while (std::isspace(stream.peek())) {
            stream.get();
        }
    };
};


#endif //HASHA_LANG_UTILS_H
