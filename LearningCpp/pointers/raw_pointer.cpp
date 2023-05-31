/***********************************
 * MMIR01. Pointers in Cpp (raw pointers)
************************************/

#include <iostream>

int main (){
    //Initializing a point always to a null value
    int * p1 {};
    [[maybe_unused]] int * p2 {nullptr};
    [[maybe_unused]] int * p3 = nullptr;
    
    //Note: [[maybe_unused]] gets rid of compiler warnings about pointers 
    // not being used

    //A good practise is checking if a pointer is null
    std::cout << (p1 == nullptr ? "p1 is null" : "p1 is not null") << "\n";
    //Or, with implicit conversion
    std::cout << (p1 ? "p1 is not null" : "p1 is null") << "\n";

    //Pointers and lvalue reference are very similar
    int x = 1;
    int& refx = x;  
    int * ptrx = &x;

    std::cout << "Value of x: " << x << '\n';
    std::cout << "Value of ref: " << refx << '\n';
    std::cout << "Value of pointer: " << *ptrx << '\n';

    //Modify x via ref
    refx = 5;
    std::cout << "Value of x: " << x << '\n';
    std::cout << "Value of ref: " << refx << '\n';
    std::cout << "Value of pointer: " << *ptrx << '\n';

    //Modify x via pointer
    *ptrx = 10;
    std::cout << "Value of x: " << x << '\n';
    std::cout << "Value of ref: " << refx << '\n';
    std::cout << "Value of pointer: " << *ptrx << '\n';

    //After using a pointer, it is recommendable to set to null
    ptrx = nullptr;

    return 0;
};
