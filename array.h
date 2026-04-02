#pragma once

#define DEFAULT 3
#include "magazines.h"



class Array{
public:
    Array();

    void arr_pushback(Magazines *value);
    void arr_del(int index);
    int get_size();
    //Magazines* get_element(int index);
    Magazines &operator [](size_t index);

    ~Array();
private:
    int size;
    int capacity;
    Magazines **arr;

    void arr_realloc();

};


