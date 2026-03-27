add_executable(jlox_tests)

target_sources(jlox_tests
        PRIVATE
        Common.h
        Common.cpp
        Scanner_test.cpp
)

target_link_libraries(jlox_tests
        PRIVATE
        lib_jlox
        GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(jlox_tests)
