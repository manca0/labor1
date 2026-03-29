#pragma once

#include "array.h"
#include "magazines.h"
#include <iostream>

namespace database {
    void print_magazines(Array *arr);
    void dwrite(Array *arr, std::string filename);
    int dread(Array *arr, std::string filename);
    void add_to_db(Array *arr, std::string filename, Magazines *mag);
    void change_name(Array *arr, std::string filename, int index, std::string u_name_mag);
    void change_theme(Array *arr, std::string filename, int index, std::string u_theme_mag);
    void change_sales(Array *arr, std::string filename, int index, int u_sales_mag);

    void delete_element(Array *arr, std::string filename, int index);

    void search_by_name(Array *arr, std::string u_name);
    void search_by_theme(Array *arr, std::string u_theme);


}




