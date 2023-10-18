/***********************************
 * MMIR01. File1 contains base class
************************************/

#include "file1.h"
#include <iostream>

namespace baseClassFolder::base {

    BaseClass::BaseClass(int a)
    {
        std::cout << "Base Class constructor\n";
        m_dataClass = a;
    }

}