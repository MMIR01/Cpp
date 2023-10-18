//Header guard
#ifndef FILE1_H
#define FILE1_H

/* Class definition here. The implementation can be
found in file1.cpp */
namespace baseClassFolder::base {
    
    class BaseClass {
    private:
        int m_dataClass;
        
    public:
        //Constructor
        BaseClass(int a);
    };
    
}

#endif