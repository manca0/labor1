#pragma once

#include "array.h"
#include "magazines.h"
#include <string>

class Database {
public:
    Database(const std::string& filename);
    ~Database();
    
    void load();
    void save() const;
    
    void print() const;
    void add(const Magazines& magazine);
    void remove(size_t index);
    
    void changeName(size_t index, const std::string& newName);
    void changeTheme(size_t index, const std::string& newTheme);
    void changeSales(size_t index, int newSales);
    
    void searchByName(const std::string& name) const;
    void searchByTheme(const std::string& theme) const;
    
    size_t getSize() const;
    const Magazines& operator[](size_t index) const;
    
private:
    std::string filename;
    Array magazines;
};