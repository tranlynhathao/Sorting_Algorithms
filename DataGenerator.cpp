#include "DataGenerator.h"

void duplicateArray(int a[], int n, int b[], int &m)
{
    m = n;
    for (int i = 0; i < n; i++)
    {
        b[i] = a[i];
    }
}

void readFile(int a[], int &n, string fileName) {
    ifstream f(fileName);
    if (!f) {
        cout << "Cannot open file" << endl;
        return;
    }

    f >> n;
    f.ignore();
    int count = 0;
    while (!f.eof()) {
        f >> a[count++];
        f.ignore();
    }
    f.close();
}

void printFile(int a[], int n, string fileName)
{
    ofstream out(fileName);
    if (!out)
    {
        cout << "Cannot opne file";
        return;
    }
    out << n << endl;
    for (int i = 0; i < n; i++)
    {
        out << a[i] << " ";
    }
    out.close();
}

// This function generates a random array
void GenerateRandomData(int a[], int n)
{
    srand((unsigned int)time(NULL));
    for (int i = 0; i < n; i++)
    {
        a[i] = rand() % n;
    }
}

// This function generates a sorted array (ascending order)
void GenerateSortedData(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        a[i] = i;
    }
}

// This function generates a reverse-sorted array (descending order)
void GenerateReverseData(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        a[i] = n - 1 - i;
    }
}

// This function generates a nearly-sorted array
void GenerateNearlySortedData(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        a[i] = i;
    }

    srand((unsigned int)time(NULL));

    for (int i = 0; i < 10; i++)
    {
        int r1 = rand() % n;
        int r2 = rand() % n;
        Swap(a[r1], a[r2]);
    }
}

void GenerateData(int a[], int n, int dataType)
{
    switch (dataType)
    {
    case 0:
        GenerateRandomData(a, n);
        break;
    case 1:
        GenerateNearlySortedData(a, n);
        break;
    case 2:
        GenerateSortedData(a, n);
        break;
    case 3:
        GenerateReverseData(a, n);
        break;
    default:
        printf("Error: unknown data type!\n");
    }
}

int GenerateDatasize(int n)
{
    switch (n)
    {
    case 0:
        return 10000;
    case 1:
        return 30000;
    case 2:
        return 50000;
    case 3:
        return 100000;
    case 4:
        return 300000;
    case 5:
        return 500000;
    default:
        return 0;
    }
}