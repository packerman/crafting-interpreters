#include "Lox.h"

#include <fstream>
#include <iostream>
#include <ostream>

#include "Scanner.h"

using namespace std;

int main(const int argc, char* argv[]) {
    if (argc > 2) {
        cout << "Usage: jlox [script]\n";
        exit(64);
    }
    jlox::Lox lox;
    if (argc == 2) {
        lox.run_file(argv[1]);
    } else {
        lox.run_prompt();
    }
}

namespace jlox {

    void Lox::run_file(const char* path) {
        if (std::ifstream in{path}; !in.is_open()) {
            cout << "failed to open " << path << '\n';
        } else {
            std::string source;
            std::string line;
            while (getline(in, line)) {
                source.append(line);
                source.push_back('\n');
            }
            run(source);

            if (had_error()) {
                exit(65);
            }
        }
    }

    void Lox::run_prompt() {
        for (;;) {
            cout << "> " << flush;
            std::string line;
            if (!getline(std::cin, line)) {
                break;
            }
            run(line);
            had_error_ = false;
        }
    }

    void Lox::report(const int line, const std::string& where, const std::string& message) {
        cerr << "[line " << line << "] Error" << where << ": " << message << '\n';
        had_error_ = true;
    }

    void Lox::run(const std::string& source) {
        Scanner scanner{source, this};

        for (const auto tokens = scanner.scan_tokens(); auto& token: tokens) {
            cout << token << '\n';
        }
    }
}
