#pragma once
#include <string>
#include <vector>

#include "ErrorReporter.h"
#include "Token.h"

namespace jlox {
    class Scanner {
    public:
        explicit Scanner(std::string source, ErrorReporter* error_reporter) : source_{std::move(source)},
                                                                              error_reporter_(error_reporter) {
        }

        std::vector<Token> scanTokens();

    private:
        [[nodiscard]] bool is_at_end() const;

        char advance();

        void add_token(TokenType type);

        void add_token(TokenType type, const Literal& literal);

        void scan_token();

        std::string source_;
        std::vector<Token> tokens_;
        ErrorReporter* error_reporter_;

        int start_{0};
        int current_{0};
        int line_{1};
    };
}
