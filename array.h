#pragma once
#define DEFAULT 3
#include "magazines.h"

class Array{
public:
    Array();
    ~Array();
    
    void arr_pushback(Magazines* value);
    void arr_del(size_t index);
    size_t get_size() const;
    
    Magazines& operator [](size_t index);
    const Magazines& operator [](size_t index) const;
    
private:
    size_t size;
    size_t capacity;
    Magazines** arr;
    
    void arr_realloc();
};