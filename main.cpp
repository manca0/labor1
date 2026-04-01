#include <iostream>
#include "database.h"
#include "magazines.h"
#include "array.h"
#include <fstream>

//using namespace dataBase;

int main(){
    Array arr;
    std::string filename;
    std::string temp_name;
    std::string temp_theme;
    std::string search_term;
    Magazines temp_mag;
    int temp_index;
    int temp_sales;
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

        std::cout << "\nEnter your choice (1-8): ";
        std::cin >> press_button;

        switch (press_button) {
            case 1:
                database::print_magazines(&arr);
                break;
            
            case 2:{
                std::cout << "\n--- ADD NEW MAGAZINE ---\n";
                std::cout << "Enter magazine name: ";
                std::cin >> temp_name;      
                std::cout << "Enter magazine theme: ";
                std::cin >> temp_theme;
                std::cout << "Enter magazine sales: ";
                std::cin >> temp_sales;

                Magazines* new_mag = new Magazines();

                new_mag->set_sales(temp_sales);
                new_mag->set_name(temp_name);
                new_mag->set_theme(temp_theme);
                database::add_to_db(&arr, filename, new_mag);
                std::cout << "Magazine added successfully!\n";
                break;
            }
            case 3:
                std::cout << "\n--- SEARCH BY NAME ---\n";
                std::cout << "Enter name to search: ";
                std::cin >> search_term;
                database::search_by_name(&arr, search_term);
                break;

            case 4:
                std::cout << "\n--- SEARCH BY THEME ---\n";
                std::cout << "Enter theme to search: ";
                std::cin >> search_term;
                database::search_by_theme(&arr, search_term);
                break;

            case 5:
                if(arr.get_size() == 0){
                    std::cout << "Database is empty!\n";
                    break;
                }
                
                std::cout << "\n--- EDIT MAGAZINE ---\n";
                std::cout << "Current database size: " << arr.get_size() << " magazines\n";
                std::cout << "Enter magazine index (0-" << arr.get_size() << "): ";
                std::cin >> temp_index;


                if(temp_index < 0 || temp_index >= arr.get_size()){
                    std::cout << "Invalid index!\n";
                    break;
                }

                int edit_choice;
                std::cout << "\nWhat do you want to edit?\n";
                std::cout << "1. Name\n";
                std::cout << "2. Theme\n";
                std::cout << "3. Sales\n";
                std::cout << "Enter choice: ";
                std::cin >> edit_choice;

                switch(edit_choice){
                    case 1:
                        std::cout << "Enter new name: ";
                        std::cin >> temp_name;
                        database::change_name(&arr,filename,temp_index, temp_name);
                        std::cout << "Name updated!\n";
                        break;
                    case 2:
                        std::cout << "Enter new theme: ";
                        std::cin >> temp_theme;
                        database::change_theme(&arr,filename,temp_index, temp_theme);
                        std::cout << "Name updated!\n";
                        break;
                    case 3:
                        std::cout << "Enter new name: ";
                        std::cin >> temp_sales;
                        database::change_sales(&arr,filename,temp_index, temp_sales);
                        std::cout << "Name updated!\n";
                        break;

                    default:
                    std::cout << "Invalid choice!\n";
                }
                break;

            case 6:
                if(arr.get_size() == 0){
                    std::cout << "Database is empty!\n";
                    break;
                }

                std::cout << "\n--- DELETE MAGAZINE ---\n";
                std::cout << "Current database size: " << arr.get_size() << " magazines\n";
                std::cout << "Enter magazine index to delete (0-" << arr.get_size() << "): ";
                std::cin >> temp_index;

                if(temp_index < 0 || temp_index >= arr.get_size()){
                    std::cout << "Invalid index!\n";
                    break;
                }

                std::cout << "Deleting magazine:\n";
                std::cout << "\nName: " << arr.get_element(temp_index)->get_name() << "\n";
                std::cout << "\nTheme: " << arr.get_element(temp_index)->get_theme() << "\n";
                std::cout << "\nSales: " << arr.get_element(temp_index)->get_sales() << "\n";

                std::cout << "Are you sure? (1=Yes, 0=No): ";
                int confirm;
                std::cin >> confirm;

                if(confirm == 1){
                    database::delete_element(&arr, filename,temp_index);
                } else{
                    std::cout << "Deletion cancelled.\n";
                }
                break;


            case 7:
                if(database::dwrite(&arr,filename)){
                    std::cout << "Databse saved to '" << filename << "'! (" << arr.get_size() << " magazines)\n";
                } else{
                    std::cout << "Error saving database!\n";
                }
                break;

            case 8:
            std::cout << "\nSaving database before exit...\n";
            database::dwrite(&arr, filename);
            std::cout << "Databse saved to '" << filename << "'. Goodbye!\n";
            break;

            default:
                std::cout << "Invalid choice! Please enter a number from 1 to 8.\n";
                break;
            }

    }
    return 0;
}