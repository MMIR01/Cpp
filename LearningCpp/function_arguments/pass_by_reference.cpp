/***********************************
 * MMIR01. Exploring arguments in
 * functions, particulary passed by
 * reference > TBW
************************************/

#include <iostream>

//Function 1. Two arguments without a default value
void function1 (int a, int b){
    std::cout << "Function 1\n";
    std::cout << "Value 1: " << a << "\n";
    std::cout << "Value 2: " << b << "\n";
}

//Function 2. Two arguments with a default value
void function2 (int a=3, int b=4){
    std::cout << "Function 2\n";
    std::cout << "Value 1: " << a << "\n";
    std::cout << "Value 2: " << b << "\n";
}

//Function 3. Only the first argument with a default value
//This is going to fail during the compilation. Reason:
//default argument should be at end of parameter list
/*
void function3 (int a=3, int b){
    std::cout << "Function 2\n";
    std::cout << "Value 1: " << a << "\n";
    std::cout << "Value 2: " << b << "\n";
}
*/

//Function 4. Only the second argument with a default value
void function4 (int a, int b=5){
    std::cout << "Function 3\n";
    std::cout << "Value 1: " << a << "\n";
    std::cout << "Value 2: " << b << "\n";
}

int main (){
    //Inserting arguments in order
    function1 (1, 2);
    //Specifying arguments > compiler error.
    // This doesn´t work in cpp
    //function1 (a=1, b=3);

    //Passing none arguments to function2
    //It should take the default values
    function2();
    //Using only 1 default value
    function2(5);

    //This is going to fail as we need to provide at least
    //the first argument
    //function4();
    function4(7);
    
    return 0;
};
