#pragma once

#include <string>
#include <unordered_map>
#include <vector>

#include "ErrorReporter.h"
#include "Token.h"

namespace jlox {
    class Scanner {
    public:
        Scanner(std::string source, ErrorReporter* error_reporter) : source_{std::move(source)},
                                                                     error_reporter_(error_reporter) {
        }

        std::vector<Token> scan_tokens();

    private:
        [[nodiscard]] bool is_at_end() const;

        char advance();

        void add_token(TokenType type);

        void add_token(TokenType type, const Literal& literal);

        bool match(char expected);

        [[nodiscard]] char peek() const;

        void string();

        static bool is_digit(char c);

        [[nodiscard]] char peek_next() const;

        void number();

        static bool is_alpha(char c);

        static bool is_alpha_numeric(char c);

        void identifier();

        void scan_token();

        std::string source_;
        std::vector<Token> tokens_;
        ErrorReporter* error_reporter_;

        int start_{0};
        int current_{0};
        int line_{1};

        inline static const std::unordered_map<std::string, TokenType> keywords_ = {
            {"and", TokenType::AND},
            {"class", TokenType::CLASS},
            {"else", TokenType::ELSE},
            {"false", TokenType::FALSE},
            {"for", TokenType::FOR},
            {"fun", TokenType::FUN},
            {"if", TokenType::IF},
            {"nil", TokenType::NIL},
            {"or", TokenType::OR},
            {"print", TokenType::PRINT},
            {"return", TokenType::RETURN},
            {"super", TokenType::SUPER},
            {"this", TokenType::THIS},
            {"true", TokenType::TRUE},
            {"var", TokenType::VAR},
            {"while", TokenType::WHILE}
        };
    };
}
