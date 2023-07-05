/***********************************
 * MMIR01. Global variables.
 * External linkage. File1
************************************/

#include <iostream>

//non-const globals are external by default
int g_a { 1 };
//const and constexpr are internal by default
const int g_b { 2 };
//use extern to make it external
extern const int g_c { 3 };

//function declaration (function prototype, forward declaration)
//function have external linkage by default (as long as forward
//declaration is used)
void print_value(int x)
{
    std::cout << "Value: " << x << "\n";
}

void print_global()
{
    //global variables can be seen here
    //g_b can be seen here but not from another file
    std::cout << "Printing global values:\n";
    std::cout << "Global a: " << g_a << "\n";
    std::cout << "Global b: " << g_b << "\n";
    std::cout << "Global c: " << g_c << "\n";
}

void change_value_g_a()
{
    g_a = 10;
    std::cout << "Global a in file1: " << g_a << "\n";
}