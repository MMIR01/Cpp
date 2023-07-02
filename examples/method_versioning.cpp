/***********************************
 * MMIR01. A simple way of versioning
 * a method by using inline namespace.
 * So this alow to have different
 * versions of the same method in the
 * same code
************************************/

#include <iostream>

inline namespace v1
{
    // V1. Print a value taken from input
    void myMethod(int value)
    {
        std::cout << "Printing value: " << value << "\n";
    }
}

namespace v2
{
    // V2. Print a value taken from input and it's double
    void myMethod(int value)
    {
        std::cout << "Printing value: " << value << "\n";
        std::cout << "It's double is: " << (value*value) << "\n";
    }
}

int main()
{
	std::cout << "Calling v1\n";
    v1::myMethod(3);
    std::cout << "Calling v2\n";
    v2::myMethod(3);
    std::cout << "Calling inline (v1 in this case)\n";
    myMethod(4);
	
	return 0;
}
