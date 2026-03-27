

add_subdirectory(lib)
add_subdirectory(tests)

add_executable(jlox)

target_sources(jlox
        PRIVATE
        Main.cpp
)

target_link_libraries(jlox
        PRIVATE
        lib_jlox)