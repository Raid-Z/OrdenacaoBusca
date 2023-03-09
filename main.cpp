#include <iostream>
#include <cstdlib>
#include <chrono>
#include <ctime>
#include <string>

using namespace std;
using namespace std::chrono;

void tSearch(int value, double *arr, int start, int end)
{
    if (end >= start)
    {
        int mid1 = start + (end - start) / 3;
        int mid2 = start - (end - start) / 3;
        if (arr[mid1] == value)
            return;

        if (arr[mid1] > value)
            tSearch(value, arr, start, mid1 - 1);
        if (arr[mid2] > value)
            tSearch(value, arr, mid1, mid2 - 1);
        tSearch(value, arr, mid2, end);
    }
    return;
}

double ternarySearch(int value, double *arr, int len)
{
    auto start = steady_clock::now();
    tSearch(value, arr, 0, len);
    auto end = steady_clock::now();
    duration<double, std::micro> time = end - start;
    double tempo = time.count();
    return tempo;
}

int bSearch(double *array, int start, int end, double value)
{
    if (end >= start)
    {
        int mid = start + (end - start) / 2;
        if (array[mid] == value)
            return mid;

        if (array[mid] > value)
            return bSearch(array, start, mid - 1, value);

        return bSearch(array, mid + 1, end, value);
    }
    return -1;
}

double binarySearch(double value, double *arr, int len)
{
    auto start = steady_clock::now();
    bSearch(arr, 0, len, value);
    auto end = steady_clock::now();
    duration<double, std::micro> time = end - start;
    double tempo = time.count();
    return tempo;
}

int Partition(double arr[], int l, int r)
{
    int pivot = arr[r];
    int i = l;
    for (int j = l; j < r; j++)
    {
        if (arr[j] <= pivot)
        {
            if (i != j)
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
            i++;
        }
    }
    int temp = arr[i];
    arr[i] = arr[r];
    arr[r] = temp;
    return i;
}

void qSort(double arr[], int l, int r)
{
    if (l <= r)
    {
        int p = Partition(arr, l, r);
        qSort(arr, l, p - 1);
        qSort(arr, p + 1, r);
    }
}

double quickSort(double *arr, int len)
{
    auto start = steady_clock::now();
    qSort(arr, 0, len);
    auto end = steady_clock::now();
    duration<double, std::micro> time = end - start;
    double tempo = time.count();
    return tempo;
}

void Merge(double *A, int l, int c, int r)
{
    int sizel = c - l + 1; // tamanho da primeira parte
    int sizer = r - c;     // tamanho da segunda parte
    int L[sizel] = {};
    int R[sizer] = {};

    for (int i = 0; i < sizel; i++)
    {
        L[i] = A[l + i]; // preenche a metade esquerda
    }
    for (int j = 0; j < sizer; j++)
    {
        R[j] = A[c + j + 1]; // preenche a metade direita
    }
    int i = 0;
    int j = 0;
    int k = l;
    while (i < sizel && j < sizer)
    { // Arruma do menor pro maior
        if (L[i] <= R[j])
        {
            A[k] = L[i];
            i++;
        }
        else
        {
            A[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < sizel)
    { // restante
        A[k] = L[i];
        i++;
        k++;
    }

    while (j < sizer)
    {
        A[k] = R[j];
        j++;
        k++;
    }
}

void mSort(double *arr, int start, int end)
{
    if (start < end)
    {
        int center = (start + end) / 2;
        mSort(arr, start, center);
        mSort(arr, center + 1, end);
        Merge(arr, start, center, end);
    }
}

double mergeSort(double *arr, int length)
{
    auto start = steady_clock::now();
    mSort(arr, 0, length);
    auto end = steady_clock::now();
    duration<double, std::micro> time = end - start;
    double tempo = time.count();
    return tempo;
    // mudança
}

double bubbleSort(double *arr, int len)
{
    cout << "tamanho do len: " << len << endl;
    auto start = steady_clock::now();

    int s = 0;
    int temp = 0;
    do
    {
        s = 0;
        for (int i = 0; i < len; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                s++;
            }
        }
    } while (s > 0);

    auto end = steady_clock::now();
    duration<double, std::micro> time = end - start;
    double tempo = time.count();
    return tempo;
}

void swap(int &a, int &b)
{
    int aux = b;
    b = a;
    a = aux;
}

double *randomArray(int len)
{
    double *arrC = new double[len];
    for (int i = 0; i <= len; i++)
    {
        arrC[i] = 0;
    }
    srand(time(0));
    for (int i = 0; i < len; i++)
    {
        arrC[i] = 20 + rand() % 1999980;
    }
    cout << "Tamanho da array: " << len << endl;
    cout << "===========================================" << endl;
    return arrC;
    int *arr = new int[len];
    srand(time(0));
    for (int i = 0; i < len; i++)
    {
        arr[i] = rand() % 5; // generate a random integer between 0 and 99
    }
    return arr;
}

double meDeUmNumero()
{
    double numProcurado = 20 + rand() % 1999980;
    cout << "O número procurado será: " << numProcurado << endl;
    return numProcurado;
}

string calculaTempo(double crono)
{

    string tempo;
    double ba = crono / 1000000.0;
    tempo = to_string(ba);

    return tempo;
}

int main()
{
    double **arr;
    arr = new double *[4];
    int tamanhos[5];
    int tamanhoVet = 0;
    int numeroProcurado = 0;
    int k, opcao;
    double cronometro = 0;
    bool saida = false;
    srand(time(0));
    for (k = 0; k < 5; k++)
    {
        tamanhoVet = 10000 + rand() % 990000;
        arr[k] = new double[tamanhoVet];
        arr[k] = randomArray(tamanhoVet);
        tamanhos[k] = tamanhoVet;
    }

    do
    {
        cout << endl
             << "Voce quer fazer qual opcao?" << endl
             << "1. Bubble" << endl
             << "2. Quick" << endl
             << "3. Merge" << endl
             << "4. Binary" << endl
             << "5. Ternary" << endl
             << "6. Saida" << endl;
        cin >> opcao;

        switch (opcao)
        {

        case 1:
            for (k = 0; k <= 4; k++)
            {
                cronometro = bubbleSort(arr[k], tamanhos[k]);
                cout << "O array " << k + 1 << " levou: " << calculaTempo(cronometro) << " segundos" << endl;
            }
            break;

        case 2:
            for (k = 0; k <= 4; k++)
            {
                cronometro = quickSort(arr[k], tamanhos[k]);
                cout << "O array " << k + 1 << " levou: " << calculaTempo(cronometro) << " segundos" << endl;
            }
            break;

        case 3:
            for (k = 0; k <= 4; k++)
            {
                cronometro = mergeSort(arr[k], tamanhos[k]);
                cout << "O array " << k + 1 << " levou: " << calculaTempo(cronometro) << " segundos" << endl;
            }
            break;

        case 4:
            numeroProcurado = meDeUmNumero();
            for (k = 0; k <= 4; k++)
            {
                cronometro = binarySearch(numeroProcurado, arr[k], tamanhos[k]);
                cout << "O array " << k + 1 << " levou: " << calculaTempo(cronometro) << " segundos" << endl;
            }
            break;

        case 5:
            numeroProcurado = meDeUmNumero();
            for (k = 0; k <= 4; k++)
            {
                cronometro = ternarySearch(numeroProcurado, arr[k], tamanhos[k]);
                cout << "O array " << k + 1 << " levou: " << calculaTempo(cronometro) << " segundos" << endl;
            }
            break;

        case 6:
            saida = true;
            break;
        }
    } while (!saida);

    for (int i = 0; i <= 4; i++)
    {
        delete[] arr[i];
    }

}
