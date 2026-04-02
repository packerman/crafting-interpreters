#include "AstPrinter.h"

#include <sstream>
#include <string>

using namespace std;

namespace jlox {
    std::string AstPrinter::print(const Expr& expr) {
        return expr.accept(this);
    }

    std::string AstPrinter::visit(const Binary* expr) {
        return parenthesize(expr->operator_token().lexeme(), {expr->left(), expr->right()});
    }

    std::string AstPrinter::visit(const Grouping* expr) {
        return parenthesize("group", {expr->expression()});
    }

    std::string AstPrinter::visit(const Literal* expr) {
        ostringstream oss;
        if (is_null(expr->value())) {
            oss << "nil";
        } else {
            oss << expr->value();
        }
        return oss.str();
    }

    std::string AstPrinter::visit(const Unary* expr) {
        return parenthesize(expr->operator_token().lexeme(), {expr->right()});
    }

    std::string AstPrinter::parenthesize(const std::string& name, std::initializer_list<const Expr *> exprs) {
        ostringstream oss;
        oss << "(" << name;
        for (const auto expr: exprs) {
            oss << " ";
            oss << expr->accept(this);
        }
        oss << ")";
        return oss.str();
    }
}
