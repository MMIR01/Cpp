//Header guard
#ifndef FILE2_H
#define FILE2_H

#include "../baseClassFolder/file1.h"

/* Class definition here. The implementation can be
found in file2.cpp */
namespace derivedClassFolder::derived {

    class DerivedClass : public baseClassFolder::base::BaseClass {
    private:
        int m_dataDerived;
        
    public:
        //Constructor
        DerivedClass(int a, int b);
    };
    
}

#endif