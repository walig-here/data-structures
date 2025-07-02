#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include <memory>


class DynamicArray
{
public:

    /**
     * Creates new dynamic array with given length & filled with given deafult value.
     * 
     * @param initial_length Initial length of the array.
     * @param default_value Value that would be used to fill the array.
     */
    DynamicArray(std::size_t initial_length = 0, int default_value = 0);
    ~DynamicArray() {};

    /* === Elements access === */
    
    // Random access
    int& operator[](std::size_t index) { return mData.get()[index]; }
    const int& operator[](std::size_t index) const { return mData.get()[index]; }

    // Acces to first element
    int& front() { return mData.get()[0]; }
    const int& front() const { return mData.get()[0]; }

    // Access to last element
    int& back() { return mData.get()[mLength - 1]; }
    const int& back() const { return mData.get()[mLength - 1]; }

    /* === Capacity === */

    // Get number of elements
    int size() const { return mLength; }

    /* === Modification === */

    /**
     * Inserts new element at selected index. The rest of the elements in the array would be shifted one position 
     * to the right.
     * 
     * @param position Index where element would be placed.
     * @param value Value that would be inserted.
     * 
     * @return Exit code.
     * @retval 0 - element inserted.
     * @retval 1 - position out of bounds.
     */
    int insert(const std::size_t position, int value);

    /**
     * Inserts new element at first position. The rest of the elements in the array would be shifted one position to the
     * right.
     * 
     * @param value Value that would be inserted.
     */
    void push_front(int value);

    /**
     * Inserts new element at last position.
     * 
     * @param value Value that would be inserted.
     */
    int push_back(int value);

    /**
     * Removes element from given position. All elements to the right of this position would be shifted one position
     * to the right. 
     * 
     * @param position Position that would be removed.
     * 
     * @return Exit code.
     * @retval 0 - element removed.
     * @retval 1 - array's empty.
     * @retval 2 - position out of bounds.
     */
    int erase(const std::size_t position);

    /**
     * Removes first element. All other elements would be shifted one position to the right.
     * 
     * @return Exit code.
     * @retval 0 - element removed.
     * @retval 1 - array's empty.
     */
    int pop_front();

    /**
     * Removes last element.
     * 
     * @return Exit code.
     * @retval 0 - element's removed.
     * @retval 1 - array's empty.
     */
    int pop_back();

private:

    std::shared_ptr<int> mData;
    int mLength;
};

#endif
