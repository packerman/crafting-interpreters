#pragma once
#include "Ast.h"

namespace jlox {
    class AstPrinter : public Expr::Visitor<std::string> {
    public:
        std::string print(const Expr& expr);

        std::string visit(const Binary*) override;

        std::string visit(const Grouping*) override;

        std::string visit(const Literal*) override;

        std::string visit(const Unary*) override;

        ~AstPrinter() override = default;

    private:
        [[nodiscard]] std::string parenthesize(const std::string& name, std::initializer_list<const Expr *> exprs);
    };
}
