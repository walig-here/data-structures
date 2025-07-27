#include <gtest/gtest.h>  // NOLINT
#include "dynamic-array.hpp"

/**
 * Preconditions
 * - No parameters are specified.
 * 
 * Expected outcome
 * - Empty array is created.
 */
TEST(ArrayInitialization, DefaultArray)
{
  DynamicArray array;
  EXPECT_EQ(array.size(), 0);
}

/**
 * Preconditions
 * - Initial length is set to 0
 * - No fill value is speficied
 * 
 * Expected outcome
 * - Empty array is created.
 */
TEST(ArrayInitialization, EmptyArray)
{
  DynamicArray array(0);
  EXPECT_EQ(array.size(), 0);
}

/**
 * Preconditions
 * - Initial length is set to 0
 * - Fill value is set to 6
 * 
 * Expected outcome
 * - Empty array is created.
 */
TEST(ArrayInitialization, EmptyArrayWithCustomFillValue)
{
  DynamicArray array(0, 6);
  EXPECT_EQ(array.size(), 0);
}

/**
 * Preconditions
 * - Initial length is set to 1
 * - Fill value is set to 6
 * 
 * Expected outcome
 * - Single-element array is created
 */
TEST(ArrayInitialization, SingleElementArray)
{
  DynamicArray array(1, 6);

  EXPECT_EQ(array.size(), 1);
  for (int i = 0; i < array.size(); i++) {
    EXPECT_EQ(array[i], 6);
  }
}

/**
 * Preconditions
 * - Length 10 is set for the array.
 * 
 * Expected outcome
 * - 10-element array filled with 0's is created
 */
TEST(ArrayInitialization, DefaultNonEmptyArray) 
{
  DynamicArray array(10);
  
  EXPECT_EQ(array.size(), 10);
  for (size_t i = 0; i < 10; ++i)
  {
    EXPECT_EQ(array[i], 0);
  }
}

/**
 * Preconditions
 * - Length 10 is set for the array.
 * - Default value for the array is set to 44
 * 
 * Expected outcome
 * - 10-element array filled with 44's is created
 */
TEST(ArrayInitialization, NonEmptyArrayWithCustomDefaultValue)
{
  DynamicArray array(10, 44);
  
  EXPECT_EQ(array.size(), 10);
  for (size_t i = 0; i < 10; ++i)
  {
    EXPECT_EQ(array[i], 44);
  }
}

/**
 * Preconditions
 * - Initial length is set to 10^6
 * - Fill value is set to 50
 * 
 * Expected outcome
 * - 10^6-elemen array filled with 50 is created
 */
TEST(ArrayInitialization, HugeArray) {
  DynamicArray array((size_t)1E6, 50);
  ASSERT_EQ(array.size(), (size_t)1E6);
  for (int i = 0; i < array.size(); i++)
  {
    ASSERT_EQ(array[i], 50);
  }
}

/**
 * Preconditions
 * - Initial lenght is maximal possible value.
 * 
 * Expected outcome
 * - Array with maximal size filled with 0's is created. Eventually when 
 * `std::bad_alloc` is thrown when there's no sufficient memory.
 */
TEST(ArrayInitialization, ArrayWithMaximalSize) {
  unsigned long size = std::numeric_limits<size_t>::max();
  try
  {
    DynamicArray array(size);
    EXPECT_EQ(array.size(), size);
    for (int i = 0; i < array.size(); i++)
    {
      EXPECT_EQ(array[i], 0);
    }
  }
  catch(const std::exception& e)
  {
    return;
  }
}
