#include "magazines.h"

Magazines::Magazines() : sales(0), name(""), theme("") {}
Magazines::Magazines(int sales, const std::string& name, const std::string& theme) 
    : sales(sales), name(name), theme(theme) {}

std::string Magazines::get_name() const {
    return name;
}

void Magazines::set_name(const std::string& value) {
    name = value;
}

std::string Magazines::get_theme() const {
    return theme;
}

void Magazines::set_theme(const std::string& value) {
    theme = value;
}

int Magazines::get_sales() const {
    return sales;
}

void Magazines::set_sales(int value) {
    sales = value;
}

std::ofstream& operator <<(std::ofstream& fos, const Magazines& magazine) {
    fos << magazine.sales << " " << magazine.name << " " << magazine.theme << "\n";
    return fos;
}

std::ifstream& operator >>(std::ifstream& fis, Magazines& magazine) {
    std::string temp_sales;
    if (std::getline(fis, temp_sales, ' ')) {
        magazine.sales = std::stoi(temp_sales);
        std::getline(fis, magazine.name, ' ');
        std::getline(fis, magazine.theme);
    }
    return fis;
}

std::ostream& operator <<(std::ostream& os, const Magazines& magazine) {
    os << "\tName: " << magazine.name << "\n";
    os << "\tTheme: " << magazine.theme << "\n";
    os << "\tSales: " << magazine.sales << "\n";
    return os;
}