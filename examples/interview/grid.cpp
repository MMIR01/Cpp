#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

string gridChallenge(vector<string> grid) {
    auto size = grid.size();
    std::cout << "Size: " << size << "\n";
    
    char first_item = grid[0][0];
    std::cout << "First item: " << first_item << "\n";

    for (unsigned long row = 0; row < size; ++row){
        
        std::cout << "Row: " << grid[row] << "\n";
        
        int pos_item = 0;
        for (unsigned long column = 0; column < grid[row].size(); ++column) {
            //std::cout << "Item: " << grid[row][column] << "\n";
            
            if (grid[row][column] < grid[row][pos_item]){
                pos_item = column;
            }
        }
        
        std::cout << "Smallest item: " << grid[row][pos_item] << "\n";
               
        if (row > 0) {
            std::cout << "Comparing: " << grid[row][pos_item] << " < " << first_item << "\n";
            
            if (grid[row][pos_item] < first_item) {
                return "NO";
            }
        }        
        
        //Save the element for next loop iteration
        first_item = grid[row][pos_item];
        //Remove the smallest element
        grid[row].erase(grid[row].begin()+pos_item);
        //std::swap(grid[row][0], grid[row][pos_item]);
        std::cout << "Result: " << grid[row] << "\n";
        
    }
    
    if (grid[0].size() == 0){
        return "YES";
    } else {
        return gridChallenge(grid);        
    }
    
    //return "NO";    

}

int main ()
{
    vector<string> mygrid{"eba", "fgh", "olm"};
    gridChallenge(mygrid);
};