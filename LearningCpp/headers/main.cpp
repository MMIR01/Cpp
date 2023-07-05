/***********************************
 * MMIR01. Example of how create 
 * and use header files
************************************/

#include "test.h"
#include "functions.h"
#include <iostream>

int main()
{
	std::cout << "Calling function defined in a different file\n";
    function1();

	std::cout << "Using a class implemented in a different file\n";
    Test test1 {1, 2, 3, 4};
	test1.getData();

	return 0;
}