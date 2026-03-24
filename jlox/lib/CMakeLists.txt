add_library(lib_jlox)

target_sources(lib_jlox
        PRIVATE
        ErrorReporter.h
        TokenType.h
        TokenType.cpp
        Token.h
        Token.cpp
        Scanner.h
        Scanner.cpp
)

target_include_directories(lib_jlox
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)