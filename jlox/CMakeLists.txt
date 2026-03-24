

add_subdirectory(lib)

add_executable(jlox)

target_sources(jlox
        PRIVATE
        Lox.h
        Lox.cpp
)

target_link_libraries(jlox
        PRIVATE
        lib_jlox)