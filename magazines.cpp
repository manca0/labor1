#include "magazines.h"



Magazines::Magazines() : sales(0), name(""), theme(""){}
Magazines::Magazines(int u_sales, std::string u_name, std::string u_theme) : sales(u_sales), name(u_name), theme(u_theme){}

std::string Magazines::get_name(){
    return this->name;
}

void Magazines::set_name(std::string value){
    this->name = value;
}

std::string Magazines::get_theme(){
    return this->theme;
}

void Magazines::set_theme(std::string value){
    this->theme = value;
}

int Magazines::get_sales(){
    return this->sales;
}

void Magazines::set_sales(int value){
    this->sales = value;
}

std::ofstream &operator <<(std::ofstream &fos, const Magazines &magazine){
    fos << magazine.sales << " " << magazine.name << " " << magazine.theme << "\n";
    return fos;
}

std::ifstream& operator >>(std::ifstream &fis, Magazines &magazine){
    std::string temp;
    std::getline(fis, temp, ' ');
    std::getline(fis, magazine.name, ' ');
    std::getline(fis, magazine.theme);
    magazine.sales = std::stoi(temp);

    return fis;
}

std::ostream& operator <<(std::ostream &os, const Magazines &magazine){
    os << "\tName: " << magazine.name << "\n";
    os << "\tTheme: " << magazine.theme << "\n";
    os << "\tSales: " << magazine.sales << "\n";
    
    return os;
}

