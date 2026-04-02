#include <gtest/gtest.h>
#include <AstPrinter.h>

namespace jlox {
    TEST(AstPrinterTest, Print_Ast) {
        auto expression = make_binary(
            make_unary(
                Token{TokenType::MINUS, "-", nullptr, 1},
                make_literal(123.0)),
                Token{TokenType::STAR, "*", nullptr, 1},
                make_grouping(
                    make_literal(45.67)));

        auto ast_printer = AstPrinter();
        const auto result = ast_printer.print(*expression);

        EXPECT_EQ(result, "(* (- 123) (group 45.67))");
    }

}
