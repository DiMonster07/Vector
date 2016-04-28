#pragma once
#include <iostream>

typedef unsigned int size_b;

template<typename T>
class Allocator
{
public:
    Allocator() {  };
    Allocator(const Allocator& alloc) {  };
    T* allocate(size_b chunk_size)
    {
        std::cout << "Allocated!" << std::endl;
        return (T*)(::operator new( chunk_size * sizeof(T) ));
    }
    void deallocate(T* ptr, size_b size)
    {
        std::cout << "Deallocated!" << std::endl;
        ::operator delete(ptr);
    }
};
