#!/bin/bash

echo "Running linter for C++ library"

clang-tidy \
    ${LIB_ROOT}/library/src/*.cpp ${LIB_ROOT}/library/include/*.hpp \
    -p build/ \
    -checks=-*,cppcoreguidelines-*,cert-*,clang-analyzer-*,cppcoreguidelines-*,modernize-*,performance-*,portability-*,readability-*,-modernize-use-trailing-return-type,-cppcoreguidelines-avoid-c-arrays,-modernize-avoid-c-arrays\
    -warnings-as-errors=* \
    -- \
    -I "${LIB_ROOT}/library/include" \
    -std=c++20 
