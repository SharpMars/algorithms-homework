#include <iostream>
#include <chrono>

using namespace std;

const int N = 10000;

void bubbleSort(int array[]) {
    auto start = chrono::steady_clock::now();

    bool swapped = false;

    do
    {
        swapped = false;
        for (int i = 1; i < N; i++)
        {
            if(array[i - 1] > array[i])
            {
                swap(array[i - 1], array[i]);
                swapped = true;
            }
        }
    } while(swapped);

    auto end = chrono::steady_clock::now();
    auto diff = end - start;

    cout << "BubbleSort: " << chrono::duration <double, milli> (diff).count() << " ms" << endl;
}

void insertSort(int array[]) {
    auto start = chrono::steady_clock::now();

    int i = 1;

    while(i < N)
    {
        int j = i;
        while(j > 0 && array[j - 1] > array[j])
        {
            swap(array[j], array[j - 1]);
            j -= 1;
        }
        i += 1;
    }

    auto end = chrono::steady_clock::now();
    auto diff = end - start;

    cout << "InsertionSort: " << chrono::duration <double, milli> (diff).count() << " ms" << endl;
}

int qsort_compare (const void * a, const void * b)
{
    if ( *(int*)a <  *(int*)b ) return -1;
    if ( *(int*)a == *(int*)b ) return 0;
    if ( *(int*)a >  *(int*)b ) return 1;

    return -2;
}

void quickSort(int array[])
{
    auto start = chrono::steady_clock::now();

    qsort(array, N, sizeof(int), qsort_compare);

    auto end = chrono::steady_clock::now();
    auto diff = end - start;

    cout << "QuickSort: " << chrono::duration <double, milli> (diff).count() << " ms" << endl;
}

void randomizeArray(int array[])
{
    for(int i = 0; i < N; i++)
    {
        array[i] = rand() % 100 + 1;
    }
}

void printArray(int array[])
{
    for(int i = 0; i < N; i++)
    {
        cout << array[i] << ' ';
    }
    cout << endl;
}

int main() {
    int array[N] = {0};

    srand(time(NULL));

    randomizeArray(array);
    bubbleSort(array);

    randomizeArray(array);
    insertSort(array);

    randomizeArray(array);
    quickSort(array);

    return 0;
}