#include <iostream>
#include "database.h"
#include "magazines.h"
#include "array.h"
#include <fstream>

//using namespace dataBase;

int main(){
    Array arr;
    std::string filename;
    int press_button = 0;

    std::cout << "=== MAGAZINES DATABASE MANAGMENT SYSTEM ===\n";

    std::cout << "Enter database filename: ";
    std::cin >> filename;

    std::cout << "Loading database from " << filename << "...\n";
    if(!(database::dread(&arr, filename))){
        std::cout << "Database loaded successfully! Found " << arr.get_size() << " magazines.\n";
    } else{
        std::cout << "Starting with empty database. New file will be created.\n";
    }

    while(press_button != 8){
        std::cout << "\n=== MAIN MENU ===\n";
        std::cout << "1. Display all magazines\n";
        std::cout << "2. Add new magazine\n";
        std::cout << "3. Search by name\n";
        std::cout << "4. Search by theme\n";
        std::cout << "5. Edit magazine\n";
        std::cout << "6. Delete magazine\n";
        std::cout << "7. Save database\n";
        std::cout << "8. Exit\n";

    }
    return 0;
}