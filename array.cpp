#include "array.h"
#include "magazines.h"
#include <cstddef>
#include <cstdlib>


Array::Array() : size(0), capacity(DEFAULT), arr(new Magazines*[DEFAULT]){}
Array::~Array(){
    capacity = 0;
    for(size_t i = 0; i < this->size; i++){
        delete this->arr[i]; 
    }
    delete[] arr;
    size = 0; 
    arr = nullptr;
}

void Array::arr_realloc(){
    int new_capacity = this->capacity*2;
    Magazines **newArr = (Magazines**)realloc(this->arr, new_capacity* sizeof(Magazines*));

    this->capacity = new_capacity;
    this->arr = newArr;
}


void Array::arr_pushback(Magazines *value){
    if(this->size >= this->capacity){
        arr_realloc();
    }

    this->arr[this->size] = value;
    this->size++;
}

void Array::arr_del(int index){
    for(size_t i = index; i < this->size-1; i++){
        this->arr[i] = this->arr[i+1];
    }
    this->size--;
}


int Array::get_size(){
    return this->size;
}

Magazines* Array::get_element(int index){
    return this->arr[index];
}
