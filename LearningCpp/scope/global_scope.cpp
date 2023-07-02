/***********************************
 * MMIR01. Checking variable
 * scopes. Global variables
************************************/

#include <iostream>

int g_a; // global variables are initialized as zero by default
constexpr int g_b { 5 }; // const and constexpr variables must be initialized

void print_value ();

int main(){

    // Global variables are seen throughout the file, so it
    // can be used here
    g_a = 1;

    std::cout << "Value of the g_variable 1: " << g_a <<  "\n";
    std::cout << "Value of the g_variable 2: " << g_b <<  "\n";


    print_value();

    return 0;
} // g_a is destroyed at the end of the program

void print_value()
{
    // global variable can be also seen here
    g_a = 2;
    std::cout << "Value of the g_variable 1: " << g_a <<  "\n";
}