#include "Token.h"

namespace jlox {
    bool operator==(const Token& lhs, const Token& rhs) {
        return lhs.token_type_ == rhs.token_type_
               && lhs.lexeme_ == rhs.lexeme_
               && lhs.literal_ == rhs.literal_
               && lhs.line_ == rhs.line_;
    }

    bool operator!=(const Token& lhs, const Token& rhs) {
        return !(lhs == rhs);
    }

    std::ostream& operator<<(std::ostream& os, const Token& token) {
        os
                << "token_type: " << token.token_type_
                << " lexeme: " << token.lexeme_
                << " literal: ";
        switch (token.token_type_) {
            case TokenType::STRING:
                os << std::get<std::string>(token.literal_);
                break;
            case TokenType::NUMBER:
                os << std::get<double>(token.literal_);
                break;
            default:
                os << std::get<std::nullptr_t>(token.literal_);
        }
        return os << " line: " << token.line_;
    }
}
