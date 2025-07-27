#!/bin/bash

cd ${LIB_BUILD}
ctest --output-on-failure

llvm-profdata merge -o unittest.profdata ${LIB_BUILD}/tests/*.profraw
llvm-cov report ${LIB_BUILD}/lib/data-structures.a -instr-profile=unittest.profdata -use-color -show-region-summary=false

llvm-cov show ${LIB_BUILD}/lib/data-structures.a \
    -instr-profile=unittest.profdata \
    -format=html \
    -show-branches=count \
> coverage.html
