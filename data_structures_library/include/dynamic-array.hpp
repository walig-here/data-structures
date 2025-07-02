#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include <memory>


class DynamicArray
{
public:

    DynamicArray(std::size_t initial_length = 0, int default_value = 0);
    ~DynamicArray() {};

    /* Elements access */
    int& operator[](std::size_t index) { return mData.get()[index]; }
    const int& operator[](std::size_t index) const { return mData.get()[index]; }
    int& front() { return mData.get()[0]; }
    const int& front() const { return mData.get()[0]; }
    int& back() { return mData.get()[mLength - 1]; }
    const int& back() const { return mData.get()[mLength - 1]; }

    /* Capacity */
    int size() const { return mLength; }

    /* Modification */
    int insert(const std::size_t position, int value);
    int push_front(int value);
    int push_back(int value);
    int erase(const std::size_t position);
    int pop_front();
    int pop_back();

private:

    std::shared_ptr<int> mData;
    int mLength;
};

#endif
