/***********************************
 * MMIR01. Templates
 * In this example we will see
 * struct templates
************************************/

#include <iostream>

template <typename T>
struct User
{
    int id{};
    T salary{};
};

//Default value for the type
template <typename T=double>
struct Car
{
    int id{};
    T price{};
};

//Deduction guide for the compiler
template <typename T>
User (T, T) -> User<T>;

int main ()
{
    User<int>  u1 = {1, 50000};
    User<double> u2  = {1, 50000.35};
    //C++ version >= 17 (class template argument deduction)
    User u3 = {3, 40000};

    std::cout << u1.salary << '\n';  //expected returned value int
    std::cout << u2.salary << '\n';  //expected returned value double
    std::cout << u3.salary << '\n';  //expected returned value int

    Car c1;
    c1.id = 1;
    c1.price = 25000.5;
    std::cout << c1.price << '\n'; 

    return 0;

}
