/***********************************
 * MMIR01. Example about how to read
 * and print string
************************************/

#include <iostream>
#include <string>

int main() {
    std::cout << "Enter a phrase with 2 words:\n";

    std::string s1{ }; // Empty string

    // std::ws > ignore whitespace
    std::getline(std::cin >> std::ws, s1);

    std::cout << "Result: \n" << s1 << "\n";

    return 0;
}