#include <iostream>

#include "Lox.h"

int main(const int argc, char* argv[]) {
    if (argc > 2) {
        std::cout << "Usage: jlox [script]\n";
        exit(64);
    }
    jlox::Lox lox;
    if (argc == 2) {
        lox.run_file(argv[1]);
    } else {
        lox.run_prompt();
    }
}