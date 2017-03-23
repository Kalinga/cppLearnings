#ifndef MY_VEC_H
#define MY_VEC_H

#include <iostream>
#include <chrono>
#include <vector>
#include <cstring>
#include <iomanip>

using namespace std::chrono;

template <typename T, class my_alloc=std::allocator<T>>
class myvec {
public:
    typedef std::size_t size_type;
    typedef my_alloc allocator_type;
    typedef const allocator_type const_allocator_type;
    
    typedef T value_type;
    typedef value_type& reference;
    typedef const value_type& const_reference;
    typedef value_type* pointer;
    typedef const pointer const_pointer;
    
    // constructors
    myvec()
        : allocator_()
        , start_()
        , size_()
        , capacity_()
    {}
    
    myvec(const myvec& vec)
        : allocator_(vec.allocator())
        , start_(allocator().allocate(vec.size()))
        , size_(vec.size())
        , capacity_(vec.size())
    {
        memcpy(start_, vec.start(), size() * sizeof(value_type));
    }
    
    myvec(myvec&& vec)
        : allocator_(std::move(vec.allocator_))
        , start_(std::move(vec.start_))
        , size_(std::move(vec.size_))
        , capacity_(std::move(vec.capacity_))
    {
        vec.start_ = 0;
        vec.size_ = 0;
        vec.capacity_ = 0;
    }
    
    ~myvec() {
        if(start_) {
            for(std::size_t i = 0; i < size(); ++i)
                start_[i].~value_type();
            
            allocator().deallocate(start_, capacity());
        }
    }
    
    // info
    size_type capacity() const { return capacity_; }
    size_type size() const { return size_; }
    
    allocator_type& allocator() { return allocator_; }
    const_allocator_type& allocator() const { return allocator_; }
    
    // modify
    void push_back(const_reference value) {
        if(capacity() == size()) // if the vector is full allocate new memory
        {
            // get new-needed space (geometric growth factor 2)
            if(capacity() != 0)
                capacity_ *= 2;
            else
                capacity_ = 1;
            
            // allocate space
            pointer temp = allocator().allocate(capacity());
            
            // then move the elements over and create the new element
            memcpy(temp, start_, size() * sizeof(value_type));
            
            allocator().deallocate(start_, size());
            start_ = temp;
        }
        new (data() + size()) value_type(value);
        
        ++size_;
    }
    
    // access
    pointer data() { return start_; }
    const_pointer data() const { return start_; }
    reference operator[](size_type position) { return start_[position]; }
    const_reference operator[](size_type position) const { return start_[position]; }
    
private:
    allocator_type allocator_;
    pointer start_;
    size_type size_;
    size_type capacity_;
};

#endif //MY_VEC_H
