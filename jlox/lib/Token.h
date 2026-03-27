#pragma once

#include <iostream>
#include <string>
#include <utility>
#include <variant>

#include "TokenType.h"

namespace jlox {
    using literal_t = std::variant<std::nullptr_t, std::string, double>;

    class Token {
    public:
        Token(const TokenType token_type, std::string lexeme, literal_t literal,
              const int line)
            : token_type_(token_type),
              lexeme_(std::move(lexeme)),
              literal_(std::move(literal)),
              line_(line) {
        }

        friend bool operator==(const Token& lhs, const Token& rhs);

        friend bool operator!=(const Token& lhs, const Token& rhs);

        friend std::ostream& operator<<(std::ostream& os, const Token& token);

    private:
        TokenType token_type_;
        std::string lexeme_;
        literal_t literal_;
        int line_;
    };
}
