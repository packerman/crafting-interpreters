#pragma once

#include <ErrorReporter.h>

namespace jlox {
    class EmptyErrorReporter : public ErrorReporter {
    public:
        bool had_error() override {
            return false;
        }

        static ErrorReporter& instance();

    protected:
        void report(int line, const std::string& where, const std::string& message) override {
        }
    };
}
