#ifndef SORT_TIME_H
#define SORT_TIME_H

#include "Lib.h"

void selectionSort(int a[], int n);
void insertionSort(int a[], int n);
void shellSort(int a[], int n);
void bubbleSort(int a[], int n);
void heapify(int a[], int n, int i);
void heapSort(int a[], int n);
void merge(int a[], int l, int m, int r);
void mergeSort(int a[], int left, int right);
int partition(int a[], int first, int last);
void quickSort(int a[], int first, int last);
int getMax(int a[], int n);
void countSort(int a[], int n, int exp);
void radixSort(int a[], int n);
int findMax(int a[], int n);
void countingSort(int a[], int n);
int binarySearch(int a[], int left, int right, int k);
void binaryInsertionSort(int a[], int n);
void shakerSort(int a[], int n);
void flashSort(int a[], int n);

#endif