add_library(lib_jlox)

target_sources(lib_jlox
        PRIVATE
        Lox.h
        Lox.cpp
        ErrorReporter.h
        TokenType.h
        TokenType.cpp
        Token.h
        Token.cpp
        Scanner.h
        Scanner.cpp
        Ast.h
        Ast.cpp
        AstPrinter.h
        AstPrinter.cpp
)

target_include_directories(lib_jlox
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)