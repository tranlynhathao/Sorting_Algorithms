#include "SortWithCompare.h"

// Selection Sort
void selectionSortWithCompare(int a[], int n, int64_t& compare)
{
    compare = 0;
    for (int i = 0; ++compare && i < n; i++)
    {
        int min = i;
        for (int j = i + 1; ++compare && j < n; j++)
        {
            if (++compare && a[j] < a[min])
            {
                min = j;
            }
        }
        if (++compare && min != i)
            swap(a[min], a[i]);
    }
}

// Insertion sort
void insertionSortWithCompare(int a[], int n, int64_t &compare)
{
    compare = 0;
    int key, j;
    for (int i = 1; ++compare && i < n; i++)
    {
        key = a[i];
        j = i - 1;

        while (++compare && j >= 0 && ++compare && a[j] > key)
        {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = key;
    }
}

// Shell Sort
void shellSortWithCompare(int a[], int n, int64_t &compare)
{
    compare = 0;
    int h = 1;
    while (++compare && h < n)
    {
        h = 3 * h + 1;
    }
    h /= 3;
    while (++compare && h >= 1)
    {
        for (int i = h; ++compare && i < n; i++)
        {
            for (int j = i; ++compare && j >= h; j -= h)
            {
                if (++compare && a[j] < a[j - h])
                {
                    swap(a[j], a[j - h]);
                }
            }
        }
        h = h / 3;
    }
}

// Bubble Sort
void bubbleSortWithCompare(int a[], int n, int64_t &compare)
{
    compare = 0;
    for (int i = 0; ++compare && i < n - 1; i++)
    {
        for (int j = 0; ++compare && j < n - i - 1; j++)
        {
            if (++compare && a[j] > a[j + 1])
                swap(a[j], a[j + 1]);
        }
    }
}

// Heap Sort
void heapifyWithCompare(int a[], int n, int i, int64_t &compare)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (++compare && left < n && ++compare && a[left] > a[largest])
    {
        largest = left;
    }
    if (++compare && right < n && ++compare && a[right] > a[largest])
    {
        largest = right;
    }
    if (++compare && largest != i)
    {
        swap(a[i], a[largest]);
        heapifyWithCompare(a, n, largest, compare);
    }
}

void heapSortWithCompare(int a[], int n, int64_t &compare)
{
    for (int i = n / 2 - 1; ++compare && i >= 0; i--)
    {
        heapifyWithCompare(a, n, i, compare);
    }
    for (int i = n - 1; ++compare && i > 0; i--)
    {
        swap(a[0], a[i]);
        heapifyWithCompare(a, i, 0, compare);
    }
}

// Merge Sort
void mergeWithCompare(int a[], int l, int m, int r, int64_t &compare)
{
    int n1 = m - l + 1;
    int n2 = r - m;

    int *left = new int[n1];
    int *right = new int[n2];

    for (int i = 0; ++compare && i < n1; i++)
        left[i] = a[l + i];
    for (int i = 0; ++compare && i < n2; i++)
        right[i] = a[m + 1 + i];

    int i = 0, j = 0, k = l;
    while (++compare && i < n1 && ++compare && j < n2)
    {
        if (++compare && left[i] <= right[j])
        {
            a[k++] = left[i++];
        }
        else
        {
            a[k++] = right[j++];
        }
    }

    while (++compare && i < n1)
    {
        a[k++] = left[i++];
    }

    while (++compare && j < n2)
    {
        a[k++] = right[j++];
    }

    delete[] left;
    delete[] right;
}

void mergeSortWithCompare(int a[], int left, int right, int64_t &compare)
{
    if (++compare && left < right)
    {
        int mid = left + (right - left) / 2;
        mergeSortWithCompare(a, left, mid, compare);
        mergeSortWithCompare(a, mid + 1, right, compare);
        mergeWithCompare(a, left, mid, right, compare);
    }
}

// Quick Sort
int partitionWithCompare(int a[], int first, int last, int64_t &compare)
{
    int pivot = a[last];
    int j = first - 1;

    for (int i = first; ++compare && i <= last - 1; i++)
    {
        if (++compare && a[i] < pivot)
        {
            j++;
            swap(a[i], a[j]);
        }
    }
    swap(a[j + 1], a[last]);
    return j + 1;
}

void quickSortWithCompare(int a[], int first, int last, int64_t &compare)
{
    if (++compare && first < last)
    {
        int pivot = partitionWithCompare(a, first, last, compare);

        quickSortWithCompare(a, first, pivot - 1, compare);
        quickSortWithCompare(a, pivot + 1, last, compare);
    }
}

// Radix Sort
int getMaxWithCompare(int a[], int n, int64_t &compare)
{
    int max = a[0];
    for (int i = 1; ++compare && i < n; i++)
    {
        if (++compare && a[i] > max)
        {
            max = a[i];
        }
    }
    return max;
}

void countSortWithCompare(int a[], int n, int exp, int64_t &compare)
{
    int output[MAX];
    int count[10] = {0};

    for (int i = 0; ++compare && i < n; i++)
    {
        count[(a[i] / exp) % 10]++;
    }

    for (int i = 1; ++compare && i < 10; i++)
    {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; ++compare && i >= 0; i--)
    {
        output[count[(a[i] / exp) % 10] - 1] = a[i];
        count[(a[i] / exp) % 10]--;
    }

    for (int i = 0; ++compare && i < n; i++)
    {
        a[i] = output[i];
    }
}

void radixSortWithCompare(int a[], int n, int64_t &compare)
{
    int m = getMaxWithCompare(a, n, compare);

    for (int exp = 1; m / exp > 0; exp *= 10)
    {
        countSortWithCompare(a, n, exp, compare);
    }
}

// Counting Sort
int findMaxWithCompare(int a[], int n, int64_t &compare)
{
    int max = INT_MIN;
    for (int i = 0; ++compare && i < n; i++)
    {
        if (++compare && max < a[i])
        {
            max = a[i];
        }
    }
    return max;
}

void countingSortWithCompare(int a[], int n, int64_t &compare)
{
    int maximum = findMaxWithCompare(a, n, compare);
    int *b = new int[maximum + 1]{0};
    for (int i = 0; ++compare && i < n; i++)
    {
        b[a[i]]++;
    }
    int temp = 0;
    for (int i = 0; ++compare && i <= maximum; i++)
    {
        while (++compare && b[i] > 0)
        {
            a[temp++] = i;
            b[i]--;
        }
    }
    delete[] b;
}

// Binary Insertion Sort
int binarySearchWithCompare(int a[], int left, int right, int k, int64_t &compare)
{
    if (++compare && right <= left)
    {
        return (k > a[left]) ? (left + 1) : left;
    }

    int mid = left + (right - left) / 2;

    if (++compare && a[mid] == k)
    {
        return mid + 1;
    }

    if (++compare && a[mid] < k)
    {
        return binarySearchWithCompare(a, mid + 1, right, k, compare);
    }

    return binarySearchWithCompare(a, left, mid - 1, k, compare);
}

void binaryInsertionSortWithCompare(int a[], int n, int64_t &compare)
{
    for (int i = 1; ++compare && i < n; i++)
    {
        int key = a[i];
        int j = i - 1;

        int loc = binarySearchWithCompare(a, 0, j, key, compare);

        while (++compare && j >= loc)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

// Shaker Sort
void shakerSortWithCompare(int a[], int n, int64_t &compare)
{
    int left = 0;
    int right = n - 1;
    int k = 0;

    while (++compare && left < right)
    {
        for (int i = left; ++compare && i < right; i++)
        {
            if (++compare && a[i] > a[i + 1])
            {
                swap(a[i], a[i + 1]);
                k = i;
            }
        }
        right = k;

        for (int i = right; ++compare && i > left; i--)
        {
            if (++compare && a[i] < a[i - 1])
            {
                swap(a[i], a[i - 1]);
                k = i;
            }
        }
        left = k;
    }
}

// Flash Sort
void flashSortWithCompare(int a[], int n, int64_t &compare)
{
    int m = n * 0.45;
    if (++compare && m < 1)
    {
        m = 1;
    }
    int maximum = INT_MIN, minimum = INT_MAX;
    for (int i = 0; ++compare && i < n; i++)
    {
        if (++compare && a[i] > maximum)
        {
            maximum = a[i];
        }
        if (++compare && a[i] < minimum)
        {
            minimum = a[i];
        }
    }

    int *b = new int[m]{0};

    for (int i = 0; ++compare && i < n; i++)
    {
        int64_t k = int64_t(m - 1) * int64_t(a[i] - minimum) / int64_t(maximum - minimum);
        b[k]++;
    }

    for (int i = 1; ++compare && i < m; i++)
    {
        b[i] += b[i - 1];
    }

    int count = 0;
    int j = 0;
    int64_t k = m - 1;
    while (++compare && count < n)
    {
        while (++compare && j >= b[k])
        {
            j++;
            k = int64_t(m - 1) * int64_t(a[j] - minimum) / int64_t(maximum - minimum);
        }
        int flash = a[j];
        while (++compare && j != b[k])
        {
            k = int64_t(m - 1) * int64_t(flash - minimum) / int64_t(maximum - minimum);
            swap(a[--b[k]], flash);
            ++count;
        }
    }

    for (int i = 1; ++compare && i < n; i++)
    {
        int key = a[i];
        int j = i - 1;
        while (++compare && j >= 0 && ++compare && a[j] > key)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }

    delete[] b;
}