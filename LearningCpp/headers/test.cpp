/***********************************
 * MMIR01. Example of how create 
 * and use header files. This file
 * contain a class implementation
************************************/

#include "test.h"
#include <iostream>

Test::Test(int data1, int data2, int data3, int data4){
    setData(data1, data2, data3, data4);
}

void Test::getData(){
    std::cout << "Printing data..." << "\n";
    std::cout << m_data1 << "\n";
    std::cout << m_data2 << "\n";
    std::cout << m_data3 << "\n";
    std::cout << m_data4 << "\n";
}

void Test::setData(int data1, int data2, int data3, int data4){
    m_data1 = data1;
    m_data2 = data2;
    m_data3 = data3;
    m_data4 = data4;
}