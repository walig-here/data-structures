#!/bin/bash

cmake -S "${LIB_ROOT}" -B "${LIB_BUILD}" -DCMAKE_EXPORT_COMPILE_COMMANDS=on
cd "${LIB_ROOT}/library"
cmake --build ${LIB_BUILD} --target "data-structures"
