#include "TokenType.h"

namespace jlox {
    std::ostream& operator<<(std::ostream& os, const TokenType token_type) {
        switch (token_type) {
            case TokenType::LEFT_PAREN:
                os << "LEFT_PAREN" << '\n';
                break;
            case TokenType::RIGHT_PAREN:
                os << "RIGHT_PAREN" << '\n';
                break;
            case TokenType::LEFT_BRACE:
                os << "LEFT_BRACE" << '\n';
                break;
            case TokenType::RIGHT_BRACE:
                os << "RIGHT_BRACE" << '\n';
                break;
            case TokenType::COMMA:
                os << "COMMA" << '\n';
                break;
            case TokenType::DOT:
                os << "DOT" << '\n';
                break;
            case TokenType::MINUS:
                os << "MINUS" << '\n';
                break;
            case TokenType::PLUS:
                os << "PLUS" << '\n';
                break;
            case TokenType::SEMICOLON:
                os << "SEMICOLON" << '\n';
                break;
            case TokenType::SLASH:
                os << "SLASH" << '\n';
                break;
            case TokenType::STAR:
                os << "STAR" << '\n';
                break;
            case TokenType::BANG:
                os << "BANG" << '\n';
                break;
            case TokenType::BANG_EQUAL:
                os << "BANG_EQUAL" << '\n';
                break;
            case TokenType::EQUAL:
                os << "EQUAL" << '\n';
                break;
            case TokenType::EQUAL_EQUAL:
                os << "EQUAL_EQUAL" << '\n';
                break;
            case TokenType::GREATER:
                os << "GREATER" << '\n';
                break;
            case TokenType::GREATER_EQUAL:
                os << "GREATER_EQUAL" << '\n';
                break;
            case TokenType::LESS:
                os << "LESS" << '\n';
                break;
            case TokenType::LESS_EQUAL:
                os << "LESS_EQUAL" << '\n';
                break;
            case TokenType::IDENTIFIER:
                os << "IDENTIFIER" << '\n';
                break;
            case TokenType::STRING:
                os << "STRING" << '\n';
                break;
            case TokenType::NUMBER:
                os << "NUMBER" << '\n';
                break;
            case TokenType::AND:
                os << "AND" << '\n';
                break;
            case TokenType::CLASS:
                os << "CLASS" << '\n';
                break;
            case TokenType::ELSE:
                os << "ELSE" << '\n';
                break;
            case TokenType::FALSE:
                os << "FALSE" << '\n';
                break;
            case TokenType::FUN:
                os << "FUN" << '\n';
                break;
            case TokenType::FOR:
                os << "FOR" << '\n';
                break;
            case TokenType::IF:
                os << "IF" << '\n';
                break;
            case TokenType::NIL:
                os << "NIL" << '\n';
                break;
            case TokenType::OR:
                os << "OR" << '\n';
                break;
            case TokenType::PRINT:
                os << "PRINT" << '\n';
                break;
            case TokenType::RETURN:
                os << "RETURN" << '\n';
                break;
            case TokenType::SUPER:
                os << "SUPER" << '\n';
                break;
            case TokenType::THIS:
                os << "THIS" << '\n';
                break;
            case TokenType::TRUE:
                os << "TRUE" << '\n';
                break;
            case TokenType::VAR:
                os << "VAR" << '\n';
                break;
            case TokenType::WHILE:
                os << "WHILE" << '\n';
                break;
            case TokenType::LOX_EOF:
                os << "EOF" << '\n';
                break;
            default:
                os << "UNKNOWN_TOKEN_TYPE" << '\n';
        }
        return os;
    }
}
