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

    bool Scanner::match(const char expected) {
        if (is_at_end()) {
            return false;
        }
        if (source_[current_] != expected) {
            return false;
        }

        current_++;
        return true;
    }

    char Scanner::peek() const {
        if (is_at_end()) {
            return '\0';
        }
        return source_[current_];
    }

    void Scanner::string() {
        while (peek() != '"' && !is_at_end()) {
            if (peek() == '\n') {
                line_++;
            }
            advance();
        }

        if (is_at_end()) {
            error_reporter_->error(line_, "Unterminated string.");
            return;
        }

        advance();

        auto value = source_.substr(start_ + 1, current_ - start_ - 2);
        add_token(TokenType::STRING, value);
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
            case '!':
                add_token(match('=') ? TokenType::BANG_EQUAL : TokenType::BANG);
                break;
            case '=':
                add_token(match('=') ? TokenType::EQUAL_EQUAL : TokenType::EQUAL);
                break;
            case '<':
                add_token(match('=') ? TokenType::LESS_EQUAL : TokenType::LESS);
                break;
            case '>':
                add_token(match('=') ? TokenType::GREATER_EQUAL : TokenType::GREATER);
                break;
            case '/':
                if (match('/')) {
                    while (peek() != '\n' && !is_at_end()) {
                        advance();
                    }
                } else {
                    add_token(TokenType::SLASH);
                }
                break;

            case ' ':
            case '\r':
            case '\t':
                break;

            case '\n':
                line_++;
                break;

            case '"':
                string();
                break;

            default:
                error_reporter_->error(line_, "Unexpected character.");
                break;
        }
    }
}
