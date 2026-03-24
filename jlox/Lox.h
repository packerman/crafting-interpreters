#pragma once
#include "lib/ErrorReporter.h"

namespace jlox {
    class Lox : public ErrorReporter {
    public:
        void run_file(const char* path);

        void run_prompt();

        bool had_error() override {
            return had_error_;
        }

    protected:
        void report(int line, const std::string& where, const std::string& message) override;

    private:
        void run(const std::string& source);

        bool had_error_ = false;
    };
}
