/***********************************
 * MMIR01. Global variables.
 * External linkage. Main
************************************/

#include <iostream>
#include "ex_linkage_file1.cpp"

//Forward declaration of variables defined in ex_linkage_file1.cpp
//(we need to use extern)
extern int g_a;
extern const int g_c;

int main(){

    //Call to a function defined in a different file
    print_value(5);
    print_global();

    //Accessing global variables
    std::cout << "Printing global values from different file:\n";
    std::cout << "Global a: " << g_a << "\n";
    std::cout << "Global c: " << g_c << "\n";

    change_value_g_a();
    //g_a will be the value changed in the other file
    std::cout << "Global a: " << g_a << "\n";


    return 0;
}