/***********************************
 * MMIR01. This is an example of
 * operator overloading via
 * friend functions
************************************/

#include <iostream>

class Car {
    std::string m_make {};
    std::string m_model {};
    int m_value {};
public:
    Car (std::string make, std::string model, int value) 
        : m_make(make), m_model(model), m_value(value) {}

    /* We need to declare here the function, but this is
    not a member function*/
    friend int operator+ (const Car& c1, const Car& c2);
};

//We want to sum two cars and get the combined value of them
int operator+ (const Car& c1, const Car& c2) {
    return c1.m_value + c2.m_value;
}

int main()
{
    Car c_one {"BMW", "Series 2", 36000};
    Car c_two {"Seat", "Ibiza", 19000};
    
    std::cout << "Fleet value: " << c_one + c_two << "\n";

    return 0;
}