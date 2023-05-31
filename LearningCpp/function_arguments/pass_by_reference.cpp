/***********************************
 * MMIR01. Exploring arguments in
 * functions, particulary passed by
 * reference
************************************/

#include <iostream>
#include <string>

//Because string is very expensive, we can also use retunr by reference
const std::string& getUserName(){
    //static otherwise the variable would be destroyed at the end of the function
    static const std::string& user_name {"John Doe"};
    return user_name;
}

//Function 1. int reference
void function1 (int& x){
    std::cout << "Value passed by reference: " << x << "\n";
    //Increasing value of x
    ++x;
}

void printValue(std::string& x)
{
    std::cout << "String value: " << x << '\n';
}

//function overload
void printValue(const int& x)
{
    std::cout << "Value: " << x << '\n';
}

int main (){
    //Inserting arguments in order
    int value1 {1};
    function1(value1);
    //In C: function1 (value1);
    std::cout << "Value after function1: " << value1 << "\n";

    //Pass by reference to non-modifiable value doesn't work
    //Reason: initial value of reference to non-const must be an lvalue
    //function1(5);

    std::string s{ "Hello, world!" };
    printValue(s);

    //Pass by const reference
    int value2 { 3 };
    //ok: value2 is a modifiable lvalue
    printValue(value2); 
    //ok: value3 is a non-modifiable lvalue
    const int value3 { 4 };
    printValue(value3); 
    //ok: 5 is a literal rvalue
    printValue(5);   
    
    //Return by reference
    std::cout << "Return by reference: " << getUserName() << "\n";
 
    return 0;
};
