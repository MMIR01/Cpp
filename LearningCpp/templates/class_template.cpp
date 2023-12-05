/***********************************
 * MMIR01. Templates
 * In this example we will see
 * class templates
************************************/
#include <iostream>

template <typename T>
class StaticArray
{
private:
    T* m_array;

public:
    StaticArray (int size) {
        m_array = new T[size]{};
    }

    void print()
    {
        std::cout << m_array << '\n';
    }

    T& operator[](int index)
    {
        return m_array[index];
    }
};


int main()
{
    // declare an integer array with room for 12 integers
    StaticArray<int> intArray{12};

    // Fill it up in order, then print it backwards
    for (int count { 0 }; count < 12; ++count)
        intArray[count] = count;

    for (int count { 11 }; count >= 0; --count)
        std::cout << intArray[count] << ' ';
    std::cout << '\n';

    return 0;
}