#pragma once

#include <memory>
#include <utility>

#include "Token.h"

namespace jlox {
    class Binary;
    class Grouping;
    class Literal;
    class Unary;

    class Expr {
    public:
        template<typename R>
        class Visitor {
        public:
            virtual ~Visitor() = default;

            virtual R visit(const Binary*) = 0;

            virtual R visit(const Grouping*) = 0;

            virtual R visit(const Literal*) = 0;

            virtual R visit(const Unary*) = 0;
        };

        virtual ~Expr() = default;

        template<typename R>
        R accept(Visitor<R>* visitor) const {
            return accept_impl(visitor);
        }

    private:
        virtual std::string accept_impl(Visitor<std::string>* visitor) const = 0;
    };

    class Binary : public Expr {
    public:
        Binary(std::unique_ptr<Expr> left, Token operator_token, std::unique_ptr<Expr> right)
            : left_(std::move(left)),
              operator_(std::move(operator_token)),
              right_(std::move(right)) {
        }

        ~Binary() override = default;

        [[nodiscard]] const Expr* left() const {
            return left_.get();
        }

        [[nodiscard]] const Token& operator_token() const {
            return operator_;
        }

        [[nodiscard]] const Expr* right() const {
            return right_.get();
        }

    private:
        std::string accept_impl(Visitor<std::string>* visitor) const override {
            return visitor->visit(this);
        }

        std::unique_ptr<Expr> left_;
        Token operator_;
        std::unique_ptr<Expr> right_;
    };

    std::unique_ptr<Expr> make_binary(std::unique_ptr<Expr> left, const Token& operator_token,
                                      std::unique_ptr<Expr> right);

    class Grouping : public Expr {
    public:
        explicit Grouping(std::unique_ptr<Expr> expression)
            : expression_(std::move(expression)) {
        }

        ~Grouping() override = default;

        [[nodiscard]] const Expr* expression() const {
            return expression_.get();
        }

    private:
        std::string accept_impl(Visitor<std::string>* visitor) const override {
            return visitor->visit(this);
        }

        std::unique_ptr<Expr> expression_;
    };

    std::unique_ptr<Expr> make_grouping(std::unique_ptr<Expr> expression);

    class Literal : public Expr {
    public:
        explicit Literal(literal_t value)
            : value_(std::move(value)) {
        }

        ~Literal() override = default;

        [[nodiscard]] const literal_t& value() const {
            return value_;
        }

    private:
        std::string accept_impl(Visitor<std::string>* visitor) const override {
            return visitor->visit(this);
        }

        literal_t value_;
    };

    std::unique_ptr<Expr> make_literal(const literal_t& value);

    class Unary : public Expr {
    public:
        Unary(Token operator_, std::unique_ptr<Expr> right)
            : operator_(std::move(operator_)),
              right_(std::move(right)) {
        }

        ~Unary() override = default;

        [[nodiscard]] const Token& operator_token() const {
            return operator_;
        }

        [[nodiscard]] const Expr* right() const {
            return right_.get();
        }

    private:
        std::string accept_impl(Visitor<std::string>* visitor) const override {
            return visitor->visit(this);
        }

        Token operator_;
        std::unique_ptr<Expr> right_;
    };

    std::unique_ptr<Expr> make_unary(const Token& operator_token, std::unique_ptr<Expr> right);
}
