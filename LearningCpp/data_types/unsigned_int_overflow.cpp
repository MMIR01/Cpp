/***********************************
 * MMIR01. Example of "modulo wrapping"
 * when there is an unsigned interger
 * overflow
************************************/

#include <iostream>

int main(){
    //Size of unsigned int on the computer
    std::cout << "Unsigned int size (bytes): " << sizeof(unsigned short int) << "\n";

    //Supposing 2 bytes. Max number 2expN - 1 = 65535
    unsigned short ok_value = 65535;
    std::cout << "This variable is ok: " << ok_value << "\n";

    //Overflow 
    unsigned short nok_value = 65536;
    //Modulo wrapping > it should print 0
    std::cout << "This variable is nok: " << nok_value << "\n";
    
    unsigned short negative_value = -1;
    //Modulo wrapping > it should print 65535
    std::cout << "This variable is nok: " << negative_value << "\n";
    
    return 0;
}