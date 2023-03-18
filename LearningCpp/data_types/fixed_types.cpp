/***********************************
 * MMIR01. Program to check the
 * some fixed-width types
************************************/

#include <cstdint>
#include <iostream>

int main()
{
 
    std::cout << "int8_t:\t\t" << sizeof(std::int8_t) << " byte\n";
    std::cout << "uint32_t:\t" << sizeof(std::uint32_t) << " bytes\n";
    //Provide the fastest type with a width of at least X bytes
    std::cout << "int_fast32_t:\t" << sizeof(std::int_fast32_t) << " bytes\n";
    //Provide the smalles type with a width of at least X bytes
    std::cout << "int_least32_t:\t" << sizeof(std::int_least32_t) << " bytes\n";

    /* Note:  Avoid using 8-bit fixed-width integer types since they are often 
    treated like chars instead of integer values */

    return 0;
}