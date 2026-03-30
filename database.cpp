#include "database.h"
#include "array.h"
#include "magazines.h"
#include <iostream>
#include <fstream>

namespace database{

    void print_magazines(Array *arr){
        std::cout << "\n=== MAGAZINES DATABASE ===\n";
        std::cout << "Total magazines: " << arr->get_size() << "\n\n";
        for(size_t i = 0; i < arr->get_size(); i++){
            std::cout << "Magazine " << i << ":\n";
            std::cout << *(arr->get_element(i));
            std::cout << "----------------------------\n";
        }
    }
    
    int dwrite(Array *arr, std::string filename){
        std::ofstream fout(filename);
    
        for(size_t i = 0; i< arr->get_size(); i++){
            fout << *(arr->get_element(i));
        }
    
        fout.close();
        return 0;
    }
    
    int dread(Array *arr, std::string filename){
        std::ifstream fin(filename);
    
        for(size_t i = 0; i < arr->get_size(); i++){
            fin >> *(arr->get_element(i));
        }
    
        fin.close();
        return 0;
    }
    
    
    void add_to_db(Array *arr, std::string filename, Magazines *mag){
        arr->arr_pushback(mag);
        dwrite(arr, filename);
    
    }
    void change_name(Array *arr, std::string filename, int index, std::string u_name_mag){
        arr->get_element(index)->set_name(u_name_mag);
        dwrite(arr, filename);
    }
    void change_theme(Array *arr, std::string filename, int index, std::string u_theme_mag){
        arr->get_element(index)->set_theme(u_theme_mag);
        dwrite(arr, filename);
    }
    void change_sales(Array *arr, std::string filename, int index, int u_sales_mag){
        arr->get_element(index)->set_sales(u_sales_mag);
        dwrite(arr, filename);
    }
    
    void delete_element(Array *arr, std::string filename, int index){
        arr->arr_del(index);
        dwrite(arr, filename);
        std::cout << "Element at index " << index << " deleted successfully!\n";
    }
    
    void search_by_name(Array *arr, std::string u_name){
        std::cout << "\n=== SEARCH RESULTS BY NAME: " << u_name << " ===\n";
        int found;
        for(size_t i = 0; i < arr->get_size(); i++){
            if(arr->get_element(i)->get_name() == u_name){
                std::cout << "Found at index " << i << ":\n";
                std::cout << *(arr->get_element(i));
                std::cout << "----------------------------\n";
                found = 1;
            }
        }

        if(!found){
            std::cout << "No magazines found with name " << u_name << "\n";
        }
    }
    void search_by_theme(Array *arr, std::string u_theme){
        std::cout << "\n=== SEARCH RESULTS BY NAME: " << u_theme << " ===\n";
        int found;
        for(size_t i = 0; i < arr->get_size(); i++){
            if(arr->get_element(i)->get_name() == u_theme){
                std::cout << "Found at index " << i << ":\n";
                std::cout << *(arr->get_element(i));
                std::cout << "----------------------------\n";
                found = 1;
            }
        }

        if(!found){
            std::cout << "No magazines found with name " << u_theme << "\n";
        }
    }
}
