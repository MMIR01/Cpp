/***********************************
 * MMIR01. Checking variable
 * scopes. Local variables
************************************/

#include <iostream>

//forward declaration
int add_values(int x, int y);

int main(){
    //a and b only have a scope limited to the main function

    //Tip: define local variables as close to their first use

    // a enters scope here
    int a{ 5 }; 
    // b enters scope here
    int b{ 6 }; 

    std::cout << add_values(a, b) << '\n'; 

    //Local variables defined in a nested block it is destroyed
    //when the block finish
    if (1){
        int c{ 7 };
        std::cout << "Value of c: " << c << '\n'; 
    }

    //This will fail here
    //std::cout << "Value of c: " << c;

    return 0;
} // b and a go out of scope and are destroyed here


//LOCAL SCOPE
int add_values(int x, int y) // x and y are created and enter scope here
{
    // x and y only are available inside function1
    return x + y;
} // y and x go out of scope and are destroyed here