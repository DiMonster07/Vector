#pragma once
#include <iostream>

typedef unsigned long int size_t;

template<typename T>
class Allocator
{
public:
    Allocator() {  };
    T* allocate(size_t chunk_size) { return (T*)(::operator new( chunk_size * sizeof(T) )); }
    void deallocate(T* ptr, size_t size) { ::operator delete(ptr); }
};
