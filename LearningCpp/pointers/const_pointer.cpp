/***********************************
 * MMIR01. Pointers to const in Cpp
 *  (raw pointers)
************************************/

#include <iostream>

int main (){
    const int x{1};
    const int* ptr {&x};

    const int y{2};
    //This is ok
    ptr = &y;

    //Same is not valid with references
    const int& ref{x};
    //Error: expression must be a modifiable lvalue
    //ref = y;

    //Pointer to const can be used with non-const
    int z {5};
    ptr = &z;
    //However, because it is a point to const, it is
    //not possible to modify the value of z
    //Error: expression must be a modifiable lvalue
    //*ptr = 7;

    //Const pointer to a const value
    const int * const ptr_const {&x};
    //In  this case, we cannot change the address of the pointer
    //not possible to modify the value of z
    //ptr_const = &y;

    return 0;
};