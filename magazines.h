#pragma once

#include <iostream>
#include <fstream>
#include <string>

class Magazines{
public:
    Magazines();
    Magazines(int sales, const std::string& name, const std::string& theme);
    
    // getters (добавим const)
    std::string get_name() const;
    std::string get_theme() const;
    int get_sales() const;
    
    // setters
    void set_name(const std::string& value);
    void set_theme(const std::string& value);
    void set_sales(int value);
    
    friend std::ofstream& operator <<(std::ofstream& fos, const Magazines& magazine);
    friend std::ifstream& operator >>(std::ifstream& fis, Magazines& magazine);
    friend std::ostream& operator <<(std::ostream& os, const Magazines& magazine);
    
private:
    std::string name;
    std::string theme;
    int sales;
};

std::ofstream& operator <<(std::ofstream& fos, const Magazines& magazine);
std::ifstream& operator >>(std::ifstream& fis, Magazines& magazine);
std::ostream& operator <<(std::ostream& os, const Magazines& magazine);