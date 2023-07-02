/***********************************
 * MMIR01. Dynamic memory allocation.
 * Multidimension
************************************/
#include <iostream>

int main (){

    //Example. Multidimension array of 3 rows 2 columns
    //array[3][2]
    int rows = 3;
    int columns = 2;
    
    //To do this dynamically:
    //Allocate memory for an array of pointers to array (rows)
    int** pparray = new(std::nothrow) int*[rows];
    
    /*For each element of the array (row), we allocate an
    integer array (columns)*/
    for (int i=0; (pparray != nullptr) && (i < rows); i++){
        pparray[i] = new(std::nothrow) int[columns];
        //Release memory in case memory can't be allocated
        if(!pparray[i]){
            //Release memory allocated
            for(int j = i-1; j>=0; j--)
                delete[] pparray[j];
            delete[] pparray;
            pparray = nullptr;
        }
    }
    
    if(!pparray)
        std::cout << "No memory allocated \n";
    else {
        //Working with our new pointer to an int pointer

        /*Access to other elements of the arrays like 
        *multidimensional arrays*/
        pparray[0][0] = 1;
        //pparray[0][1]
        (*pparray)[1] = 2;
        pparray[1][0] = 3;
        //pparray[1][1]
        *(*(pparray+1)+1) = 4;
        //pparray[2][0]
        *(pparray+2)[0] = 5;
        //pparray[2][1]
        *(pparray[2]+1) = 6;

        //Print elements
        //for each is not available when using dynamic memory allocation
        for (int row=0; row < rows; row++){
            for (int col = 0; col < columns; col++){
                printf("Value of array[%d][%d]: %d\n", row, col, pparray[row][col]);
            }
        }

        //Release memory
        for (int row=0; row < rows; row++){
            delete[] pparray[row];
        }
        delete[] pparray;
        pparray = nullptr;

    }

    return 0;
};
