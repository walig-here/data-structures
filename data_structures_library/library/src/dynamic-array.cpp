#ifndef DYNAMIC_ARRAY_CPP
#define DYNAMIC_ARRAY_CPP

#include <stdexcept>

#include "dynamic-array.hpp"

DynamicArray::DynamicArray(const std::size_t& initial_length, const int& default_value):
    mLength(initial_length)
{
    mData = std::shared_ptr<int[]>(new int[mLength]);
    for (int& element : std::span<int>(mData.get(), mLength))
    {
        element = default_value;
    }
}

DynamicArray::DynamicArray(const DynamicArray &to_copy):
    mLength(to_copy.mLength)
{
    throw std::logic_error("Not yet implemented!");
}

DynamicArray &DynamicArray::operator=(const DynamicArray &to_copy)
{
    throw std::logic_error("Not yet implemented!");
}

int DynamicArray::insert(const std::size_t& position, const int& value)
{
    throw std::logic_error("Not yet implemented!");
}

void DynamicArray::push_front(const int& value)
{
    throw std::logic_error("Not yet implemented!");
}

void DynamicArray::push_back(const int& value)
{
    throw std::logic_error("Not yet implemented!");
}

int DynamicArray::erase(const std::size_t& position)
{
    throw std::logic_error("Not yet implemented!");
}

#endif
