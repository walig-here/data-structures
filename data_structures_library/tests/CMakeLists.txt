include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/52eb8108c5bdec04579160ae17225d66034bd723.zip
)
FetchContent_MakeAvailable(googletest)

add_executable(
    ${TEST_TARGET_NAME}
    "ut/dynamic-array/default-initialization.cpp"
)

target_link_libraries(
    ${TEST_TARGET_NAME}
    PRIVATE
        ${LIB_TARGET_NAME}
        GTest::gtest_main
)

set_target_properties(
    ${TEST_TARGET_NAME}
    PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)

include(GoogleTest)
gtest_discover_tests(${TEST_TARGET_NAME} 
    DISCOVERY_MODE PRE_TEST
    PROPERTIES
        ENVIRONMENT "LLVM_PROFILE_FILE=coverage-%m-%p.profraw"
)
