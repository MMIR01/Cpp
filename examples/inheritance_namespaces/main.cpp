/***********************************
 * MMIR01. How can we derive
 * from a class in a different
 * namespace?
 ************************************/

#include "baseClassFolder/file1.h"
#include "derivedClassFolder/file2.h"
#include <iostream>

int main()
{
	//std::cout << "Creating base class object\n";
    //base::BaseClass baseObject{4};

	std::cout << "Creating derived class object\n";
    derivedClassFolder::derived::DerivedClass derivedObject{1,2};

	
	return 0;
}
