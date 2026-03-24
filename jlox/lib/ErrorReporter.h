#pragma once
#include <string>

namespace jlox {
    class ErrorReporter {
    public:
        virtual ~ErrorReporter() = default;

        void error(const int line, const std::string& message) {
            report(line, "", message);
        }

        virtual bool had_error() = 0;

    protected:
        virtual void report(int line, const std::string& where, const std::string& message) = 0;
    };
}
