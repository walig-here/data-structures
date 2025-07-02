cmake_minimum_required(VERSION 3.22.1)

# Setup build for library
project("Data Structure Library")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_library(
  "data-structures"
  STATIC
  "src/dynamic-array.cpp"
)
include_directories(
  "include"
)

# Enable testing with google tests
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/52eb8108c5bdec04579160ae17225d66034bd723.zip
)
FetchContent_MakeAvailable(googletest)
enable_testing()
add_executable(
    data-structures-tests
    "test/test.cpp"
)
target_link_libraries(
    data-structures-tests
    GTest::gtest_main
)
include(GoogleTest)
gtest_discover_tests(data-structures-tests)
