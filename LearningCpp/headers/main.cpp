/***********************************
 * MMIR01. Example of how create 
 * and use header files
************************************/

#include "functions.h"
#include <iostream>

int main()
{
	std::cout << "Calling function defined in a different file\n";
    function1();
	
	return 0;
}