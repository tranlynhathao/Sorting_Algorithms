#ifndef DATA_H
#define DATA_H
#include "Lib.h"
template <class T>
void Swap(T &a, T &b)
{
    T x = a;
    a = b;
    b = x;
}
void readFile(int a[], int &n, string fileName);
void printFile(int a[], int n, string fileName);
void duplicateArray(int a[], int n, int b[], int &m);
void GenerateRandomData(int a[], int n);
void GenerateSortedData(int a[], int n);
void GenerateReverseData(int a[], int n);
void GenerateNearlySortedData(int a[], int n);
void GenerateData(int a[], int n, int dataType);
int GenerateDatasize(int n);
#endif