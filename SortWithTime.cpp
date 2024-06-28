#include "SortWithTime.h"

// Selection Sort
void selectionSort(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		int min = i;
		for (int j = i + 1; j < n; j++)
		{
			if (a[j] < a[min])
			{
				min = j;
			}
		}
		if (min != i)
			swap(a[min], a[i]);
	}
}

// Insertion sort
void insertionSort(int a[], int n)
{
	int key, j;
	for (int i = 1; i < n; i++)
	{
		key = a[i];
		j = i - 1;

		while (j >= 0 && a[j] > key)
		{
			a[j + 1] = a[j];
			j = j - 1;
		}
		a[j + 1] = key;
	}
}

// Shell Sort
void shellSort(int a[], int n)
{
	int h = 1;
	while (h < n)
	{
		h = 3 * h + 1;
	}
	h /= 3;
	while (h >= 1)
	{
		for (int i = h; i < n; i++)
		{
			for (int j = i; j >= h; j -= h)
			{
				if (a[j] < a[j - h])
				{
					swap(a[j], a[j - h]);
				}
			}
		}
		h = h / 3;
	}
}

// Bubble Sort
void bubbleSort(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (a[j] > a[j + 1])
				swap(a[j], a[j + 1]);
		}
	}
}

// Heap Sort
void heapify(int a[], int n, int i)
{
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	if (left < n && a[left] > a[largest])
	{
		largest = left;
	}
	if (right < n && a[right] > a[largest])
	{
		largest = right;
	}
	if (largest != i)
	{
		swap(a[i], a[largest]);
		heapify(a, n, largest);
	}
}

void heapSort(int a[], int n)
{
	for (int i = n / 2 - 1; i >= 0; i--)
	{
		heapify(a, n, i);
	}
	for (int i = n - 1; i > 0; i--)
	{
		swap(a[0], a[i]);
		heapify(a, i, 0);
	}
}

// Merge Sort
void merge(int a[], int l, int m, int r)
{
	int n1 = m - l + 1;
	int n2 = r - m;

	int* left = new int[n1];
	int* right = new int[n2];

	for (int i = 0; i < n1; i++)
		left[i] = a[l + i];
	for (int i = 0; i < n2; i++)
		right[i] = a[m + 1 + i];

	int i = 0, j = 0, k = l;
	while (i < n1 && j < n2)
	{
		if (left[i] <= right[j])
		{
			a[k++] = left[i++];
		}
		else
		{
			a[k++] = right[j++];
		}
	}

	while (i < n1)
	{
		a[k++] = left[i++];
	}

	while (j < n2)
	{
		a[k++] = right[j++];
	}

	delete[] left;
	delete[] right;
}

void mergeSort(int a[], int left, int right)
{
	if (left < right)
	{
		int mid = left + (right - left) / 2;
		mergeSort(a, left, mid);
		mergeSort(a, mid + 1, right);
		merge(a, left, mid, right);
	}
}

// Quick Sort

int partition(int a[], int first, int last)
{
	int pivot = a[last];
	int j = first - 1;

	for (int i = first; i <= last - 1; i++)
	{
		if (a[i] < pivot)
		{
			j++;
			swap(a[i], a[j]);
		}
	}
	swap(a[j + 1], a[last]);
	return j + 1;
}

void quickSort(int a[], int first, int last)
{
	if (first < last)
	{
		int pivot = partition(a, first, last);
		quickSort(a, first, pivot - 1);
		quickSort(a, pivot + 1, last);
	}
}

// Radix Sort
int getMax(int a[], int n)
{
	int max = a[0];
	for (int i = 1; i < n; i++)
	{
		if (a[i] > max)
		{
			max = a[i];
		}
	}
	return max;
}

void countSort(int a[], int n, int exp)
{
	int output[MAX];
	int count[10] = { 0 };

	for (int i = 0; i < n; i++)
	{
		count[(a[i] / exp) % 10]++;
	}

	for (int i = 1; i < 10; i++)
	{
		count[i] += count[i - 1];
	}

	for (int i = n - 1; i >= 0; i--)
	{
		output[count[(a[i] / exp) % 10] - 1] = a[i];
		count[(a[i] / exp) % 10]--;
	}

	for (int i = 0; i < n; i++)
	{
		a[i] = output[i];
	}
}

void radixSort(int a[], int n)
{
	int m = getMax(a, n);

	for (int exp = 1; m / exp > 0; exp *= 10)
	{
		countSort(a, n, exp);
	}
}

// Counting Sort
int findMax(int a[], int n)
{
	int max = INT_MIN;
	for (int i = 0; i < n; i++)
	{
		if (max < a[i])
		{
			max = a[i];
		}
	}
	return max;
}

void countingSort(int a[], int n)
{
	int maximum = findMax(a, n);
	int* b = new int[maximum + 1] {0};
	for (int i = 0; i < n; i++)
	{
		b[a[i]]++;
	}
	int temp = 0;
	for (int i = 0; i <= maximum; i++)
	{
		while (b[i] > 0)
		{
			a[temp++] = i;
			b[i]--;
		}
	}
	delete[] b;
}

// Binary Insertion Sort
int binarySearch(int a[], int left, int right, int k)
{
	if (right <= left)
	{
		return (k > a[left]) ? (left + 1) : left;
	}

	int mid = left + (right - left) / 2;

	if (a[mid] == k)
	{
		return mid + 1;
	}

	if (a[mid] < k)
	{
		return binarySearch(a, mid + 1, right, k);
	}

	return binarySearch(a, left, mid - 1, k);
}

void binaryInsertionSort(int a[], int n)
{
	for (int i = 1; i < n; i++)
	{
		int key = a[i];
		int j = i - 1;

		int loc = binarySearch(a, 0, j, key);

		while (j >= loc)
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = key;
	}
}

// Shaker Sort
void shakerSort(int a[], int n)
{
	int left = 0;
	int right = n - 1;
	int k = 0;

	while (left < right)
	{
		for (int i = left; i < right; i++)
		{
			if (a[i] > a[i + 1])
			{
				swap(a[i], a[i + 1]);
				k = i;
			}
		}
		right = k;

		for (int i = right; i > left; i--)
		{
			if (a[i] < a[i - 1])
			{
				swap(a[i], a[i - 1]);
				k = i;
			}
		}
		left = k;
	}
}

// Flash Sort
void flashSort(int a[], int n)
{
	int m = n * 0.45;
	if (m < 1)
	{
		m = 1;
	}
	int maximum = INT_MIN, minimum = INT_MAX;
	for (int i = 0; i < n; i++)
	{
		if (a[i] > maximum)
		{
			maximum = a[i];
		}
		if (a[i] < minimum)
		{
			minimum = a[i];
		}
	}

	int* b = new int[m] {0};

	for (int i = 0; i < n; i++)
	{
		int64_t k = int64_t(m - 1) * int64_t(a[i] - minimum) / int64_t(maximum - minimum);
		b[k]++;
	}

	for (int i = 1; i < m; i++)
	{
		b[i] += b[i - 1];
	}

	int count = 0;
	int j = 0;
	int64_t k = m - 1;
	while (count < n)
	{
		while (j >= b[k])
		{
			j++;
			k = int64_t(m - 1) * int64_t(a[j] - minimum) / int64_t(maximum - minimum);
		}
		int flash = a[j];
		while (j != b[k])
		{
			k = int64_t(m - 1) * int64_t(flash - minimum) / int64_t(maximum - minimum);
			swap(a[--b[k]], flash);
			++count;
		}
	}

	for (int i = 1; i < n; i++)
	{
		int key = a[i];
		int j = i - 1;
		while (j >= 0 && a[j] > key)
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = key;
	}

	delete[] b;
}