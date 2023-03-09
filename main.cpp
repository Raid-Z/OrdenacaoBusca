#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int* randomArray(int len)
{
    int *arrC = new int[len];
    for (int i=0; i <= len;i++){
        arrC[i] = 0;
    }
    srand(time(0));
    for (int i = 0; i < len; i++){
        arrC[i] = 20 + rand()%1999980; // generate a random integer between 20 and 2000000
    }
    return arrC;
}

int main()
{
    int **arr;
    arr = new int * [4];
    int tamanhoVet = 0;
    int numeroProcurado = 0;
    int k;
    for (k = 0; k <= 4; k++){
        srand(time(0));
        tamanhoVet = 10000 + rand()%990000;
        arr[k] = new int [tamanhoVet];
        arr[k] = randomArray(tamanhoVet);
    }

    do{
        cout << "Procure um numero no array:" << endl;
        cin >> numeroProcurado;
    } while(!(numeroProcurado > 20 && numeroProcurado < 2000000));


    for (int i=0; i <= 4;i++){
        delete[] arr[i];
    }

    return 0;
}
