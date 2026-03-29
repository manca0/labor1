#ifndef DATABASE_H 
#define DATABASE_H

#include "array.h"
#include "magazines.h"
#include <iostream>

namespace database {
    //бинарные запись и вывод в файл
    void dwrite(Array *arr, std::string filename);
    void dread(Array *arr, std::string filename);
}




#endif