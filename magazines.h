#pragma once

#include <iostream>
#include <fstream>
#include <ostream>

class Magazines{
public:
    Magazines();
    Magazines(int u_sales, std::string u_name, std::string u_theme);

    //  get/set name
    std::string get_name();
    void set_name(std::string value);

    // get/set theme
    std::string get_theme();
    void set_theme(std::string value);

    // get/set sales
    int get_sales();
    void set_sales(int value);

    friend std::ofstream& operator <<(std::ofstream &fos, const Magazines &magazine);
    friend std::ifstream& operator >>(std::ifstream &fis, Magazines &magazine);
    friend std::ostream& operator <<(std::ostream &os, const Magazines &magazine);
private:
    std::string name;
    std::string theme;
    int sales;
};


std::ofstream& operator <<(std::ofstream &fos, const Magazines &magazine);
std::ifstream& operator >>(std::ifstream &fis, Magazines &magazine);
std::ostream& operator <<(std::ostream &os, const Magazines &magazine);



