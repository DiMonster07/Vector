#pragma once

#include <iostream>
#include <initializer_list>

template<typename T, typename Alloc = std::allocator<T>>
class Vector
{
public:
    typedef T value_type;
    typedef Alloc allocator_type;
    typedef typename allocator_type::reference       reference;
    typedef typename allocator_type::const_reference const_reference;
    typedef typename allocator_type::size_type       size_type;
    typedef typename allocator_type::difference_type difference_type;
    typedef typename allocator_type::pointer         pointer;
    typedef typename allocator_type::const_pointer   const_pointer;
    typedef pointer       iterator;
    typedef const_pointer const_iterator;
    typedef std::reverse_iterator<iterator> reverse_iterator;
    typedef std::reverse_iterator<const_iterator> const_reverse_iterator;
    const size_type m_default_size = 16;
private:
    pointer m_start;
    pointer m_finish;
    pointer m_end_of_storage;
    allocator_type m_allocator;
public:

    //Default constructor

    Vector() : m_start(nullptr), m_finish(nullptr), m_end_of_storage(nullptr)
    {
        std::cout << "Vector constructed " << std::endl;
    };

    Vector(const allocator_type& alloc) : Vector()
    {
        this->m_allocator = alloc;
        std::cout << "Vector constructed(with allocator) " << std::endl;
    };

    Vector(size_type size) : Vector()
    {
        this->m_default_initialize(size);
        std::cout << "Vector constructed(with size) = " << size << std::endl;
    };

    Vector(size_type size, value_type value) : Vector()
    {
        this->m_fill_initialize(size, value);
        std::cout << "Vector constructed(with size, value) = " << size << std::endl;
    };

    ~Vector()
    {
        std::cout << "Vector destructed " << std::endl;
    };

private:

    void m_default_initialize(size_type size)
    {
        this->m_start = this->m_allocator.allocate(size);
        this->m_finish = this->m_start;
        this->m_end_of_storage = this->m_start + size;
    };

    void m_fill_initialize(size_type size, value_type value)
    {
        this->m_default_initialize(size);
        for(pointer i = this->m_start; i <= this->m_end_of_storage; i++) { this->m_allocator.construct(i, value); }
    };
};
