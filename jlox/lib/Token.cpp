#include "Token.h"

namespace jlox {
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
