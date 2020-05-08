#include "sorting_algorithms.h"

void swap(int* xp, int* yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}


void selectionSort(int arr[], int size)
{
    int i, j, min_idx;

    for (i = 0; i < size - 1; i++)
    {
        min_idx = i;
        for (j = i + 1; j < size; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;

        swap(&arr[min_idx], &arr[i]);
    }
}


void bubbleSort(int arr[], int size)
{
    int i, j;
    for (i = 0; i < size - 1; i++)
        for (j = 0; j < size - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
}


void insertionSort(int arr[], int size)
{
    int i, key, j;
    for (i = 1; i < size; i++)
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}


void merge(int arr[], int lhs, int mid, int rhs)
{
    int i, j, k;
    const int n1 = mid - lhs + 1;
    const int n2 = rhs - mid;
    int* L = new int[n1];
    int* R = new int[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[lhs + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    i = 0, j = 0, k = lhs;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int lhs, int rhs)
{
    if (lhs < rhs)
    {
        int mid = lhs + (rhs - lhs) / 2;

        mergeSort(arr, lhs, mid);
        mergeSort(arr, mid + 1, rhs);

        merge(arr, lhs, mid, rhs);
    }
}


int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}


void heapify(int arr[], int size, int i)
{
    int largest = i;
    int lhs = 2 * i + 1;
    int rhs = 2 * i + 2; 

    if (lhs < size && arr[lhs] > arr[largest])
        largest = lhs;

    if (rhs < size && arr[rhs] > arr[largest])
        largest = rhs;

    if (largest != i)
    {
        swap(&arr[i], &arr[largest]);
        heapify(arr, size, largest);
    }
}

void heapSort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i > 0; i--)
    {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}


void countSort(int arr[], int size, int exp)
{
    int* output = new int[size];
    int i, count[10] = { 0 };

    for (i = 0; i < size; i++)
        count[(arr[i] / exp) % 10]++;

    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (i = size - 1; i >= 0; i--)
    {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    for (i = 0; i < size; i++)
        arr[i] = output[i];
}



int getMax(int arr[], int n)
{
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}

void radixsort(int arr[], int n)
{
    int m = getMax(arr, n);

    for (int exp = 1; m / exp > 0; exp *= 10)
        countSort(arr, n, exp);
}


void shellSort(int arr[], int size)
{
    for (int gap = size / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < size; i += 1)
        {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];

            arr[j] = temp;
        }
    }
}

void CocktailSort(int a[], int size)
{
    bool swapped = true;
    int start = 0;
    int end = size - 1;

    while (swapped) {
        swapped = false;

        for (int i = start; i < end; ++i) {
            if (a[i] > a[i + 1]) {
                swap(&a[i], &a[i + 1]);
                swapped = true;
            }
        }

        if (!swapped)
            break;

        swapped = false;
        --end;

        for (int i = end - 1; i >= start; --i) {
            if (a[i] > a[i + 1]) {
                swap(&a[i], &a[i + 1]);
                swapped = true;
            }
        }
        ++start;
    }
}