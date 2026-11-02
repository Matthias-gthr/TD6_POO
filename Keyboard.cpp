#include "Keyboard.h"
#include <iostream>

int Keyboard::read() const 
{

    int val;

    std::cout << "Entrez une valeur : ";
    std::cin >> val;

    return val;
}