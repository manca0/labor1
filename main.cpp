#include<fstream>
#include <string>
//#include<iostream>
#include "magazines.h"


int main(){
    Magazines mag2;
    Magazines mag1;
    std::ifstream fin("base.txt");

    fin >> mag2;    
    fin >> mag1;

    std::cout << mag1;
    std::cout << mag2;

    fin.close();
    return 0;
}