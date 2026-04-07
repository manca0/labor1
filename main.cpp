#include <iostream>
#include "database.h"



int main() {
    std::string filename;
    std::cout << "=== MAGAZINES DATABASE MANAGEMENT SYSTEM ===\n";
    std::cout << "Enter database filename: ";
    std::cin >> filename;
    
    Database db(filename);
    std::cout << "Database loaded successfully! Found " << db.getSize() << " magazines.\n";
    
    int choice = 0;
    while (choice != 8) {
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
        std::cin >> choice;
        
        switch (choice) {
            case 1:
                db.print();
                break;
                
            case 2: {
                std::cout << "\n--- ADD NEW MAGAZINE ---\n";
                std::string name, theme;
                int sales;
                
                std::cout << "Enter magazine name: ";
                std::getline(std::cin, name);
                if (name.empty()) std::getline(std::cin, name);
                
                std::cout << "Enter magazine theme: ";
                std::getline(std::cin, theme);
                
                std::cout << "Enter magazine sales: ";
                if (!(std::cin >> sales)) {
                    std::cin.clear();
                    std::cin.ignore(32767, '\n');
                    sales = 0;
                    std::cout << "Invalid input! Sales set to 0.\n";
                }
                
                db.add(Magazines(sales, name, theme));
                std::cout << "Magazine added successfully!\n";
                break;
            }
            
            case 3: {
                std::cout << "\n--- SEARCH BY NAME ---\n";
                std::string search_term;
                std::cout << "Enter name to search: ";
                std::cin >> search_term;
                db.searchByName(search_term);
                break;
            }
            
            case 4: {
                std::cout << "\n--- SEARCH BY THEME ---\n";
                std::string search_term;
                std::cout << "Enter theme to search: ";
                std::cin >> search_term;
                db.searchByTheme(search_term);
                break;
            }
            
            case 5: {

                size_t index;
                int edit_choice;
                if (db.getSize() == 0) {
                    std::cout << "Database is empty!\n";
                    break;
                }
                
                std::cout << "\n--- EDIT MAGAZINE ---\n";
                std::cout << "Current database size: " << db.getSize() << " magazines\n";
                std::cout << "Enter magazine index (0-" + std::to_string(db.getSize() - 1) + "): ";
                std::cin >> index;
                

                if (index >= db.getSize()) {
                    std::cout << "Invalid index!\n";
                    break;
                }
                
                std::cout << "\nWhat do you want to edit?\n1. Name\n2. Theme\n3. Sales\nEnter choice: ";
                std::cin >> edit_choice;
                
                switch(edit_choice) {
                    case 1: {
                        std::string new_name;
                        std::cout << "Enter new name: ";
                        std::cin >> new_name;
                        db.changeName(index, new_name);
                        std::cout << "Name updated!\n";
                        break;
                    }
                    case 2: {
                        std::string new_theme;
                        std::cout << "Enter new theme: ";
                        std::cin >> new_theme;
                        db.changeTheme(index, new_theme);
                        std::cout << "Theme updated!\n";
                        break;
                    }
                    case 3: {
                        
                        int new_sales;
                        
                        std::cout << "Enter new sales: ";
                        if (!(std::cin >> new_sales)) {
                            std::cin.clear();
                            std::cin.ignore(32767, '\n');
                            new_sales = 0;
                            std::cout << "Invalid input! Sales set to 0.\n";
                        }



                        db.changeSales(index, new_sales);
                        std::cout << "Sales updated!\n";
                        break;
                    }
                    default:
                        std::cout << "Invalid choice!\n";
                }
                break;
            }
            
            case 6: {
                if (db.getSize() == 0) {
                    std::cout << "Database is empty!\n";
                    break;
                }
 
                
                size_t index;
                std::cout << "\n--- DELETE MAGAZINE ---\n";
                std::cout << "Current database size: " << db.getSize() << " magazines\n";
                
                
                std::cout << "Enter magazine index to delete (0-" + std::to_string(db.getSize() - 1) + "): ";
                
                std::cin >> index;
                
                if (index >= db.getSize()) {
                    std::cout << "Invalid index!\n";
                    break;
                }
                
                std::cout << "Deleting magazine:\n";
                std::cout << "Name: " << db[index].get_name() << "\n";
                std::cout << "Theme: " << db[index].get_theme() << "\n";
                std::cout << "Sales: " << db[index].get_sales() << "\n";

                int confirm;
                std::cout << "Are you sure? (1=Yes, 0=No): ";
                std::cin >> confirm;

                if (confirm == 1) {
                    db.remove(index);
                } else {
                    std::cout << "Deletion cancelled.\n";
                }
                break;
            }
            
            case 7:
                db.save();
                std::cout << "Database saved to '" << filename << "'! (" << db.getSize() << " magazines)\n";
                break;
                
            case 8:
                std::cout << "\nSaving database before exit...\n";
                db.save();
                std::cout << "Database saved to '" << filename << "'. Goodbye!\n";
                break;
                
            default:
                std::cout << "Invalid choice! Please enter a number from 1 to 8.\n";
        }
    }
    return 0;
}