/***********************************
 * MMIR01. Dynamic memory allocation.
 * Arrays
************************************/
#include <iostream>

int main (){

    std::cout << "Introduce input lenght: " << "\n";
    
    int lenght {0};
    std::cin >> lenght;

    int * parray { new int [lenght]{}};

    for (int i = 0; i < lenght; i++) {
        std::cout << "Introduce integer " << i+1 << ": \n";
        std::cin >> parray[i];
    }
    

    delete[] parray;

    return 0;
};
