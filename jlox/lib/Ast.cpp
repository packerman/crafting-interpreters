#include "Ast.h"

using namespace std;

namespace jlox {
    std::unique_ptr<Expr> make_binary(std::unique_ptr<Expr>& left, const Token& operator_token,
                                      std::unique_ptr<Expr>& right) {
        return make_unique<Binary>(std::move(left), operator_token, std::move(right));
    }

    std::unique_ptr<Expr> make_grouping(std::unique_ptr<Expr>& expression) {
        return make_unique<Grouping>(std::move(expression));
    }

    std::unique_ptr<Expr> make_literal(const literal_t& value) {
        return make_unique<Literal>(value);
    }

    std::unique_ptr<Expr> make_unary(const Token& operator_token, std::unique_ptr<Expr>& right) {
        return make_unique<Unary>(operator_token, std::move(right));
    }
}
