#pragma once

void swap(int* xp, int* yp);
void merge(int arr[], int lhs, int mid, int rhs);
int partition(int arr[], int low, int high);
void heapify(int arr[], int size, int i);
int getMax(int arr[], int n);

void selectionSort(int arr[], int size);
void bubbleSort(int arr[], int size);
void insertionSort(int arr[], int size);
void mergeSort(int arr[], int lhs, int rhs);
void quickSort(int arr[], int low, int high);
void heapSort(int arr[], int n);
void countSort(int arr[], int n, int exp);
void radixsort(int arr[], int n);
void shellSort(int arr[], int size);
void CocktailSort(int a[], int size);