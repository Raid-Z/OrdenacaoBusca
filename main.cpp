#include <iostream>
#include <cstdlib>
#include <ctime>

void randomArray(int len, int *arr)
{
    arr = new int[len];
    srand(time(0));
    for (int i = 0; i < len; i++)
    {
        arr[i] = rand() % 100; // generate a random integer between 0 and 99
    }
}

int main()
{
    int *arr;
    randomArray(1000000, arr);
}