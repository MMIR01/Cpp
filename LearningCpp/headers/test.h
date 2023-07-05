
/* Use a header file for classes when they are reusable 
(used in multiple files) or for general reuse. It is 
recommendable to name the header file with the same
name as the class.

Define member trivial constructors or destructors, 
access functions, etc… inside the class, otherwise,
define them in a cpp file with the same name as the
class.*/

//Header guard
#ifndef TEST_H
#define TEST_H

/* Class definition here. The implementation can be
found in test.cpp */
class Test {
private:
    int m_data1;
    int m_data2;
    int m_data3;
    int m_data4;
    
public:
    //Constructor
    Test(int data1, int data2, int data3, int data4);

    //Gets and sets
    void getData();
    void setData(int data1, int data2, int data3, int data4);

};

#endif