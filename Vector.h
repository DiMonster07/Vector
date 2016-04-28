#pragma once

#include "allocator.h"

template<typename T, typename Alloc = Allocator<T>>
class Vector
{
public:
    typedef T value_type;
    typedef T* ptr_type;
    typedef T& ref_type;
    typedef Alloc allocator_type;
    class Iterator
    {
        Iterator() { };
    };

    struct Chunk
    {
        size_b chunk_size;
        ptr_type start;
        ptr_type finish;
        ptr_type end_of_storage;
        Chunk() : start(0), finish(0), end_of_storage(0) {};
    };

    Chunk chunk;

    Vector() { };

    Vector(size_b n, const allocator_type& alloc = allocator_type())
    {
        std::cout << "Vector constructed without defenition" << std::endl;
        this->chunk.chunk_size = n;
        this->create_storage(n);
        this->initialize_storage(n, this->chunk.start, value_type());
    };

    Vector(size_b n, const value_type value, const allocator_type& alloc = allocator_type()) : Vector(n, alloc)
    {
        std::cout << "Vector constructed with defenition" << std::endl;
        this->initialize_storage(n, this->chunk.start, value);
    };

    ~Vector()
    {
        std::cout << "Vector destructed " << std::endl;
    };

    void create_storage(size_b n)
    {
        this->chunk.start = allocator_type().allocate(n);
        this->chunk.finish = this->chunk.start;
        this->chunk.start = this->chunk.start + n;
    }

    void initialize_storage(size_b n, value_type* ptr_start, value_type value)
    {
        for (unsigned int i = 0; i < n; i++) { ptr_start[i] = value; }
    }

};
