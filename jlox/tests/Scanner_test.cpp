#include <gtest/gtest.h>

#include <Scanner.h>

#include <vector>

using namespace std;

#include "Common.h"

namespace jlox {
    std::vector<Token> run_scanner(const std::string& source) {
        static EmptyErrorReporter error_reporter;
        Scanner scanner{source, &error_reporter};
        return scanner.scan_tokens();
    }

    class ScannerTest : public testing::TestWithParam<std::tuple<std::string, vector<Token> > > {
    };

    TEST_P(ScannerTest, Scan_tokens) {
        auto [source, tokens] = GetParam();

        const auto result = run_scanner(source);

        EXPECT_EQ(result, tokens);
    }

    INSTANTIATE_TEST_SUITE_P(
        ScannerTestSuite,
        ScannerTest,
        testing::Values(
            make_tuple("", vector<Token>({
                Token{TokenType::END_OF_FILE, "", nullptr, 1}
                })),
            make_tuple(R"(
                + - * /
                )",
                vector<Token>({
                    {TokenType::PLUS, "+", nullptr, 2},
                    {TokenType::MINUS, "-", nullptr, 2},
                    {TokenType::STAR, "*", nullptr, 2},
                    {TokenType::SLASH, "/", nullptr, 2},
                    {TokenType::END_OF_FILE, "", nullptr, 3}
                    })),
            make_tuple(R"(
                "one", "two"; "three".
            )",
                vector<Token>({
                    {TokenType::STRING, "\"one\"", "one", 2},
                    {TokenType::COMMA, ",", nullptr, 2},
                    {TokenType::STRING, "\"two\"", "two", 2},
                    {TokenType::SEMICOLON, ";", nullptr, 2},
                    {TokenType::STRING, "\"three\"", "three", 2},
                    {TokenType::DOT, ".", nullptr, 2},
                    {TokenType::END_OF_FILE, "", nullptr, 3}
                    })),
            make_tuple(R"(
                123
                -123
                123.456
                )",
                vector<Token>({
                    {TokenType::NUMBER, "123", 123.0, 2},
                    {TokenType::MINUS, "-", nullptr, 3},
                    {TokenType::NUMBER, "123", 123.0, 3},
                    {TokenType::NUMBER, "123.456", 123.456, 4},
                    {TokenType::END_OF_FILE, "", nullptr, 5}
                    })
            )
        ));
}
