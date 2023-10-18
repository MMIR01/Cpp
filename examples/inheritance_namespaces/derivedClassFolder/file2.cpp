/***********************************
 * MMIR01. File1 contains base class
************************************/

#include "../baseClassFolder/file1.h"
#include "file2.h"
#include <iostream>

namespace derivedClassFolder::derived {

    DerivedClass::DerivedClass(int a, int b) :
    baseClassFolder::base::BaseClass::BaseClass{a}, m_dataDerived(b)
    {
        std::cout << "Derived Class Constructor\n";
    }

}