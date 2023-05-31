/***********************************
 * MMIR01. Templates
 * In this example we will see
 * function templates
************************************/

#include <iostream>

template <typename T>
void printValue(T x)
{
    std::cout << "Value: " << x << '\n';

}

// Multiple templates
template <typename T, typename U>
auto multiplyValue(T x, U y)
{
    // We used auto to let the compliler decide what is the type to return
    return x * y;
}

int main ()
{
    // How to call printValue
    // Op1. Using <> to declare the type
    printValue<int>(1);
    // Op2. Template argument deduction
    printValue<>(2);
    printValue(3);
    // It deducts here that the type is double
    printValue(4.5);
    
    // Multiple templates
    std::cout << multiplyValue(3, 5) << '\n';     //expected returned value int
    std::cout << multiplyValue(2.5, 2) << '\n';   //expected returned value double
    std::cout << multiplyValue(2.5, 2.5) << '\n'; //expected returned value double


    return 0;

}
