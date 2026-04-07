#include "database.h"
#include <iostream>
#include <fstream>

Database::Database(const std::string& filename) : filename(filename) {
    load();
}

Database::~Database() = default;

void Database::load() {
    std::ifstream fin(filename);
    if (!fin.is_open()) return;
    
    Magazines temp;
    while (fin >> temp) {
        magazines.arr_pushback(new Magazines(temp));
    }
    fin.close();
}

void Database::save() const {
    std::ofstream fout(filename);
    for (size_t i = 0; i < magazines.get_size(); ++i) {
        fout << magazines[i];
    }
    fout.close();
}

void Database::print() const {
    std::cout << "\n=== MAGAZINES DATABASE ===\n";
    std::cout << "Total magazines: " << magazines.get_size() << "\n\n";
    for (size_t i = 0; i < magazines.get_size(); ++i) {
        std::cout << "Magazine " << i << ":\n";
        std::cout << magazines[i];
        std::cout << "----------------------------\n";
    }
}

void Database::add(const Magazines& magazine) {
    magazines.arr_pushback(new Magazines(magazine));
    save();
}

void Database::remove(size_t index) {
    if (index < magazines.get_size()) {
        magazines.arr_del(index);
        save();
        std::cout << "Element at index " << index << " deleted successfully!\n";
    }
}

void Database::changeName(size_t index, const std::string& newName) {
    if (index < magazines.get_size()) {
        magazines[index].set_name(newName);
        save();
    }
}

void Database::changeTheme(size_t index, const std::string& newTheme) {
    if (index < magazines.get_size()) {
        magazines[index].set_theme(newTheme);
        save();
    }
}

void Database::changeSales(size_t index, int newSales) {
    if (index < magazines.get_size()) {
        magazines[index].set_sales(newSales);
        save();
    }
}

void Database::searchByName(const std::string& name) const {
    std::cout << "\n=== SEARCH RESULTS BY NAME: " << name << " ===\n";
    bool found = false;
    for (size_t i = 0; i < magazines.get_size(); ++i) {
        if (magazines[i].get_name() == name) {
            std::cout << "Found at index " << i << ":\n";
            std::cout << magazines[i];
            std::cout << "----------------------------\n";
            found = true;
        }
    }
    if (!found) {
        std::cout << "No magazines found with name " << name << "\n";
    }
}

void Database::searchByTheme(const std::string& theme) const {
    std::cout << "\n=== SEARCH RESULTS BY THEME: " << theme << " ===\n";
    bool found = false;
    for (size_t i = 0; i < magazines.get_size(); ++i) {
        if (magazines[i].get_theme() == theme) {
            std::cout << "Found at index " << i << ":\n";
            std::cout << magazines[i];
            std::cout << "----------------------------\n";
            found = true;
        }
    }
    if (!found) {
        std::cout << "No magazines found with theme " << theme << "\n";
    }
}

size_t Database::getSize() const {
    return magazines.get_size();
}

const Magazines& Database::operator[](size_t index) const {
    return magazines[index];
}