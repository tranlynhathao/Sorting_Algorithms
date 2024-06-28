// sort.h
#ifndef SORT_COMPARE_H
#define SORT_COMPARE_H
#include "Lib.h"

void selectionSortWithCompare(int a[], int n, int64_t &compare);
void insertionSortWithCompare(int a[], int n, int64_t &compare);
void shellSortWithCompare(int a[], int n, int64_t &compare);
void bubbleSortWithCompare(int a[], int n, int64_t &compare);
void heapifyWithCompare(int a[], int n, int i, int64_t &compare);
void heapSortWithCompare(int a[], int n, int64_t &compare);
void mergeWithCompare(int a[], int l, int m, int r, int64_t &compare);
void mergeSortWithCompare(int a[], int left, int right, int64_t &compare);
int partitionWithCompare(int a[], int first, int last, int64_t &compare);
void quickSortWithCompare(int a[], int first, int last, int64_t &compare);
int getMaxWithCompare(int a[], int n, int64_t &compare);
void countSortWithCompare(int a[], int n, int exp, int64_t &compare);
void radixSortWithCompare(int a[], int n, int64_t &compare);
int findMaxWithCompare(int a[], int n, int64_t &compare);
void countingSortWithCompare(int a[], int n, int64_t &compare);
int binarySearchWithCompare(int a[], int left, int right, int k, int64_t &compare);
void binaryInsertionSortWithCompare(int a[], int n, int64_t &compare);
void shakerSortWithCompare(int a[], int n, int64_t &compare);
void flashSortWithCompare(int a[], int n, int64_t &compare);

#endif
