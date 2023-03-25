#include "gtest/gtest.h"
#include "data-structures/Heap.h"


// Sprzawdzenie działania usuwania elementu z niepustego kopca
TEST(HeapTest, RemoveRootNonEmpty){

    vector<int> elements = { 27, 13, 25, 10 };
    Heap heap(elements);

    heap.pop_root();

    ASSERT_EQ(*heap.root(), 25);

}

// Sprzawdzenie działania usuwania elementu z pustego kopca
TEST(HeapTest, RemoveRootEmpty){

    vector<int> elements;
    Heap heap(elements);

    heap.pop_root();

    ASSERT_EQ(heap.root(), nullptr);

}

// Sprawdzenie działania dodawania elementu do niepustego kopca
TEST(HeapTest, AddToHeapNonEmpty){

    vector<int> elements =      { 27, 13, 25, 10 };
    vector<int> modified_heap = { 30, 27, 25, 10, 13};
    Heap heap(elements);

    heap.add(30);

    ASSERT_EQ(*heap.root(), 30);

}

// Sprawdzenie działania dodawania elementu do pustego kopca
TEST(HeapTest, AddToHeapEmpty){

    vector<int> elements;
    vector<int> modified_heap = { 13 };
    Heap heap(elements);

    heap.add(13);

    ASSERT_EQ(*heap.root(), 13);

}

// Sprawdzenie działania budowy kopca za pomocą algorytmu Floyda
TEST(HeapTest, BuildWithFloyd){

    vector<int> elements =          { 26, 19, 14, 20, 6, 4, 27, 29, 18, 5, 23, 12 };
    vector<int> sorted_elements =   { 29, 26, 27, 20, 23, 12, 14, 19, 18, 5, 6, 4 };
    Heap heap(elements); 

    ASSERT_EQ(*heap.root(), 29);

}

// Wyuszukanie w kopcu nieistniejącego elementu
TEST(HeapTest, SearchForNonExisting){

    vector<int> elements = { 26, 19, 14, 20, 6, 4, 27, 29, 18, 5, 23, 12 };
    Heap heap(elements);

    ASSERT_EQ(heap.find(9999), nullptr);

}

// Wyuszukanie w kopcu istniejącego elementu
TEST(HeapTest, SearchForExisting){

    vector<int> elements = { 26, 19, 14, 20, 6, 4, 27, 29, 18, 5, 23, 12 };
    Heap heap(elements);

    int* found_element = heap.find(19);

    ASSERT_NE(found_element, nullptr);
    ASSERT_EQ(*found_element, 19);

}

// Entry point modułu testującego klasę Arithmetic
int main(int argc, char const *argv[])
{
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}
