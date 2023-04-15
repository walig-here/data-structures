g++ test/TestHeap.cpp src/examinations/*.cpp src/data-structures/*.cpp src/app/modules/*.cpp src/app/utility/*.cpp -std=c++14 -o heap-test -I headers -I "D:\C++ Development\lib\googletest\googletest\include" "D:\C++ Development\lib\googletest\googletest\gtest.a" -pthread 

heap-test.exe
del heap-test.exe