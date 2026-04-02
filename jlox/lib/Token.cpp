#include "Token.h"

#include <variant>

using namespace std;

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
        return os
               << "token_type: " << token.token_type_
               << " lexeme: '" << token.lexeme_ << "'"
               << " literal: " << token.literal_
               << " line: " << token.line_;
    }

    std::ostream& operator<<(std::ostream& os, const literal_t& literal) {
        struct Visitor {
            std::ostream& os;

            std::ostream& operator()(const std::nullptr_t& value) const {
                return os << value;
            }

            std::ostream& operator()(const std::string& value) const {
                return os << value;
            }

            std::ostream& operator()(const double value) const {
                return os << value;
            }
        };
        return std::visit(Visitor{os}, literal);
    }

    bool is_null(const literal_t& literal) {
        return holds_alternative<nullptr_t>(literal);
    }
}
