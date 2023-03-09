#include <iostream>
#include <cstdlib>
#include <ctime>
#include "search.hpp"
#include "sort.hpp"

using namespace std;

int* randomArray(int len)
{
    int *arr = new int[len];
    srand(time(0));
    for (int i = 0; i < len; i++)
    {
        arr[i] = rand() % 5; // generate a random integer between 0 and 99
    }
    return arr;
}

int main()
{
    int *arr = randomArray(10);
    quickSort(arr, 10);
    cout << ternarySearch(3,arr,10) << endl;
    return 0;
}