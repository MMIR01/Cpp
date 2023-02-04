/***********************************
 * MMIR01. Read 2 numbers from 
 * the keyboard and print them
************************************/

#include <iostream>

int main() {
    std::cout << "Enter 2 numbers separated by space\n";

    int first_num{ }; // Value initialization
    int second_num{ 0 }; // Direct list initialization

    std::cin >> first_num >> second_num;

    std::cout << "First number: " << first_num << "\n";
    std::cout << "Second number: " << second_num << "\n";

    return 0;
}