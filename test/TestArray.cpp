#include "gtest/gtest.h"
#include "data-structures/DynamicArray.h"

// Sprawdzenie działania funkcji swap
TEST(ArrayUtils, SwapElements){

    vector<int> elements =          { 13,19,22,  16  ,27,18,12,  17  ,28 };
    vector<int> swaped_elements =   { 13,19,22,  17  ,27,18,12,  16  ,28 };
    DynamicArray array(elements); 

    array.swap(3, 7);
    for(int i = 0; i < array.getLength(); i++)
        ASSERT_EQ(*(array[i]), swaped_elements[i]);

}

// Entry point modułu testującego klasę Arithmetic
int main(int argc, char const *argv[])
{
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}
