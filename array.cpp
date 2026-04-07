#include "array.h"
#include "magazines.h"

Array::Array() : size(0), capacity(DEFAULT), arr(new Magazines*[DEFAULT]) {
    for(size_t i = 0; i < capacity; ++i) {
        arr[i] = nullptr;
    }
}

Array::~Array(){
    for(size_t i = 0; i < size; ++i){
        delete arr[i];
    }
    delete[] arr;
    size = 0;
    capacity = 0;
    arr = nullptr;
}

void Array::arr_realloc(){
    size_t new_capacity = capacity * 2;
    Magazines** newArr = new Magazines*[new_capacity];
    
    for(size_t i = 0; i < size; ++i) {
        newArr[i] = arr[i];
    }
    
    for(size_t i = size; i < new_capacity; ++i) {
        newArr[i] = nullptr;
    }
    
    delete[] arr;
    arr = newArr;
    capacity = new_capacity;
}

void Array::arr_pushback(Magazines* value){
    if(size >= capacity){
        arr_realloc();
    }
    arr[size++] = value;
}

void Array::arr_del(size_t index){
    if(index >= size) return;
    
    delete arr[index];
    
    for(size_t i = index; i < size - 1; ++i){
        arr[i] = arr[i+1];
    }
    size--;
}

size_t Array::get_size() const {
    return size;
}

Magazines& Array::operator [](size_t index){
    return *(arr[index]);
}

const Magazines& Array::operator [](size_t index) const {
    return *(arr[index]);
}