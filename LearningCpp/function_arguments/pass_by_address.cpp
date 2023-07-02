/***********************************
 * MMIR01. Exploring arguments in
 * functions, particulary passed by
 * address (using pointers)
************************************/

#include <iostream>
#include <string>

bool function1 (int * x){
    //It is always good checking pointer is not null
    if(!x){
        std::cout <<"Error: value of the pointer is null\n";
        return false;
    }

    std::cout << "Value got: " << *x << "\n";
    std::cout << "Modifying value of x\n";
    (*x)++;

    return true;
}

void printString (std::string * ptr){
    std::cout << "String passed by address: " << *ptr << "\n";
}

int main (){

    int x{1};
    function1(&x);
    std::cout << "Value after function1: " << x << "\n";

    //We can also pass a pointer
    int * ptr {&x};
    function1(ptr);
    std::cout << "Value after function1: " << *ptr << "\n";

    //Checking our function when using a null_ptr
    int *nptr{nullptr};
    function1(nptr);

    std::string s{ "Hello, world!" };
    printString(&s);
    
    return 0;
};
