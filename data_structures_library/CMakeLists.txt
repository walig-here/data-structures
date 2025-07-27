cmake_minimum_required(VERSION 3.22.1)

project("Data Structure Library")
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -fprofile-instr-generate -fcoverage-mapping")
SET(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} -fprofile-instr-generate")

set(LIB_TARGET_NAME "data-structures")
set(TEST_TARGET_NAME "data-structures-tests")

enable_testing()

add_subdirectory(library)
add_subdirectory(tests)
