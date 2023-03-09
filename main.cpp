#include <iostream>
#include <cstdlib>
#include <ctime>
#include "sort.hpp"
#include "search.hpp"

int* randomArray(int len);

int main()
{
    int *arr = randomArray(10);
    quickSort(arr,10);
    std::cout << ternarySearch(100, arr, 10);
    return 0;
}

int* randomArray(int len)
{
    int *arr = new int[len];
    srand(time(0));
    for (int i = 0; i < len; i++)
    {
        arr[i] = rand() % 100; // generate a random integer between 0 and 99
    }
    return arr;
}
