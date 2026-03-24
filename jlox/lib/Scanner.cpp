#include "Scanner.h"

namespace jlox {
    std::vector<Token> Scanner::scan_tokens() {
        while (!is_at_end()) {
            start_ = current_;
            scan_token();
        }

        tokens_.emplace_back(TokenType::LOX_EOF, "", nullptr, line_);
        return tokens_;
    }

    bool Scanner::is_at_end() const {
        return current_ >= source_.length();
    }

    char Scanner::advance() {
        return source_[current_++];
    }

    void Scanner::add_token(const TokenType type) {
        add_token(type, nullptr);
    }

    void Scanner::add_token(TokenType type, const Literal& literal) {
        auto text = source_.substr(start_, current_ - start_);
        tokens_.emplace_back(type, text, literal, line_);
    }

    void Scanner::scan_token() {
        switch (const char c = advance()) {
            case '(':
                add_token(TokenType::LEFT_PAREN);
                break;
            case ')':
                add_token(TokenType::RIGHT_PAREN);
                break;
            case '{':
                add_token(TokenType::LEFT_BRACE);
                break;
            case '}':
                add_token(TokenType::RIGHT_BRACE);
                break;
            case ',':
                add_token(TokenType::COMMA);
                break;
            case '.':
                add_token(TokenType::DOT);
                break;
            case '-':
                add_token(TokenType::MINUS);
                break;
            case '+':
                add_token(TokenType::PLUS);
                break;
            case ';':
                add_token(TokenType::SEMICOLON);
                break;
            case '*':
                add_token(TokenType::STAR);
                break;
            default:
                error_reporter_->error(line_, "Unexpected character.");
                break;
        }
    }
}
