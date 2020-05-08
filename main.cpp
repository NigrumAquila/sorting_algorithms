#include <iostream>
#include "src/sorting_algorithms.h"

using namespace std;


void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int arr[] = {
        50, 49, 48, 47, 46, 45, 44, 43, 42, 41,
        40, 39, 38, 37, 36, 35, 34, 33, 32, 31,
        30, 29, 28, 27, 26, 25, 24, 23, 22, 21,
        20, 19, 18, 17, 16, 15, 14, 13, 12, 11,
        10, 9, 8, 7, 6, 5, 4, 3, 2, 1

    };
    int size = sizeof(arr) / sizeof(arr[0]);
    
    //selectionSort(arr, size);
    //bubbleSort(arr, size);
    //insertionSort(arr, size);
    //mergeSort(arr, 0, size - 1);
    //quickSort(arr, 0, size - 1);
    //heapSort(arr, size);
    //radixsort(arr, size);
    //shellSort(arr, size);
    CocktailSort(arr, size);

    printArray(arr, size);

	return 0;
}