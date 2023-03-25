g++ test/TestArray.cpp src/data-structures/*.cpp src/app/modules/*.cpp src/app/utility/*.cpp -std=c++14 -o array-test -I headers -I "D:\C++ Development\lib\googletest\googletest\include" "D:\C++ Development\lib\googletest\googletest\gtest.a" -pthread 
cls
array-test.exe
del array-test.exe