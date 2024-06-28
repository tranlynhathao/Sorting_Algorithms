#include "CommandLine.h"

int64_t runSortingAlgorithmWithCompare(int a[], int n, int i, int64_t& compare)
{
	switch (i)
	{
	case 0:
		selectionSortWithCompare(a, n, compare);
		return compare;
		break;
	case 1:
		insertionSortWithCompare(a, n, compare);
		return compare;
		break;
	case 2:
		shellSortWithCompare(a, n, compare);
		return compare;
		break;
	case 3:
		bubbleSortWithCompare(a, n, compare);
		return compare;
		break;
	case 4:
		heapSortWithCompare(a, n, compare);
		return compare;
		break;
	case 5:
		mergeSortWithCompare(a, 0, n - 1, compare);
		return compare;
		break;
	case 6:
		quickSortWithCompare(a, 0, n - 1, compare);
		return compare;
		break;
	case 7:
		radixSortWithCompare(a, n, compare);
		return compare;
		break;
	case 8:
		countingSortWithCompare(a, n, compare);
		return compare;
		break;
	case 9:
		binaryInsertionSortWithCompare(a, n, compare);
		return compare;
		break;
	case 10:
		shakerSortWithCompare(a, n, compare);
		return compare;
		break;
	case 11:
		flashSortWithCompare(a, n, compare);
		return compare;
		break;
	default:
		break;
	}
  return compare;
}

void runSortingAlgorithmWithTime(int a[], int n, int i) {
	switch (i) {
	case 0:

		selectionSort(a, n);
		break;

	case 1:

		insertionSort(a, n);
		break;

	case 2:

		shellSort(a, n);
		break;

	case 3:

		bubbleSort(a, n);
		break;

	case 4:

		heapSort(a, n);
		break;

	case 5:

		mergeSort(a, 0, n - 1);
		break;

	case 6:

		quickSort(a, 0, n - 1);
		break;

	case 7:

		radixSort(a, n);
		break;

	case 8:

		countingSort(a, n);
		break;

	case 9:

		binaryInsertionSort(a, n);
		break;

	case 10:

		shakerSort(a, n);
		break;

	case 11:

		flashSort(a, n);
		break;

	default:
		break;
	}
}

void command1(string algo, string file, string para) {

	string sortT[12] = { "selection-sort", "insertion-sort", "shell-sort", "bubble-sort", "heap-sort", "merge-sort", "quick-sort", "radix-sort", "counting-sort", "binary-insertion-sort", "shaker-sort", "flash-sort" };

	cout << "Algorithm: ";
	int algoIndex = -1;
	for (int i = 0; i < sizeof(sortT) / sizeof(sortT[0]); i++) {
		if (algo == sortT[i]) {
			cout << sortT[i] << endl;
			algoIndex = i;
			break;
		}
	}

	if (algoIndex == -1) {
		cerr << "Algorithm not found" << endl;
		return;
	}

	int a[MAX], n = 0;

	readFile(a, n, file);
	if (n == 0) {
		cerr << "Failed to read input file or file is empty" << endl;
		return;
	}
	int b[MAX];
	int m = 0;
	duplicateArray(a, n, b, m);
	cout << "Input file: " << file << endl;
	cout << "Input size: " << n << endl;

	int64_t compare = 0;
	double time = 0;

	if (para != "-both" && para != "-time" && para != "-comp") {
		cout << "Invalid parameter" << endl;
		return;
	}

	if (para == "-both" || para == "-time") {
		auto start = chrono::high_resolution_clock::now();
		runSortingAlgorithmWithTime(a, n, algoIndex);
		auto end = chrono::high_resolution_clock::now();
		chrono::duration<double, milli> duration = end - start;
		time = duration.count();
	}

	if (para == "-both" || para == "-comp") {
		compare = runSortingAlgorithmWithCompare(b, n, algoIndex, compare);
	}

	if (para == "-time" || para == "-both") {
		cout << "Running time: " << time << " ms" << endl;
	}

	if (para == "-comp" || para == "-both") {
		cout << "Comparisons: " << compare << endl;
	}
	printFile(a, n, "output.txt");
}

void command2(string algo, string inputSize, string inputOrder, string para)
{
	string sortT[12] = { "selection-sort", "insertion-sort", "shell-sort", "bubble-sort", "heap-sort", "merge-sort", "quick-sort", "radix-sort", "counting-sort", "binary-insertion-sort", "shaker-sort", "flash-sort" };

	int i = 0;
	for (; i < 12; i++)
	{
		if (algo == sortT[i])
		{
			break;
		}
	}
	cout << "Algorithm: " << sortT[i] << endl;
	long long size = stoi(inputSize);
	cout << "Input size: " << size << endl;
	int order = -1;
	if (inputOrder == "-rand")
	{
		cout << "Input order: randomized data" << endl;
		order = 0;
	}
	else if (inputOrder == "-nsorted")
	{
		cout << "Input order: nearly sorted data" << endl;
		order = 3;
	}
	else if (inputOrder == "-sorted")
	{
		cout << "Input order: sorted data" << endl;
		order = 1;
	}
	else if (inputOrder == "-rev")
	{
		cout << "Input order: reverse sorted data" << endl;
		order = 2;
	}
	else {
		cout << "Invalid order" << endl;
		return;
	}
	cout << "------------------------------------" << endl;
	int a[MAX];
	GenerateData(a, size, order);
	printFile(a, size, "input.txt");
	int b[MAX];
	int m = 0;
	duplicateArray(a, size, b, m);
	int64_t compare = 0;
	double time = 0;

	if (para != "-both" && para != "-time" && para != "-comp") {
		cout << "Invalid parameter" << endl;
		return;
	}

	if (para == "-both" || para == "-time") {
		auto start = chrono::high_resolution_clock::now();
		runSortingAlgorithmWithTime(a, size, i);
		auto end = chrono::high_resolution_clock::now();
		chrono::duration<double, milli> duration = end - start;
		time = duration.count();
	}
	if (para == "-both" || para == "-comp") {
		compare = runSortingAlgorithmWithCompare(b, size, i, compare);
	}

	if (para == "-time" || para == "-both") {
		cout << "Running time: " << time << " ms" << endl;
	}

	if (para == "-comp" || para == "-both") {
		cout << "Comparisons: " << compare << endl;
	}
	printFile(a, size, "output.txt");
}

void command3(string algo, string sizeStr, string para) {

	string sortT[12] = { "selection-sort", "insertion-sort", "shell-sort", "bubble-sort", "heap-sort", "merge-sort", "quick-sort", "radix-sort", "counting-sort", "binary-insertion-sort", "shaker-sort", "flash-sort" };
	if (!isInteger(sizeStr)) {
		cout << "Invalid input size" << endl;
		return;
	}
	int size = stoi(sizeStr);
	if (size > 1000000) {
		cout << "Oversize" << endl;
		return;
	}

	string orders[] = { "Randomize", "Nearly Sorted", "Sorted", "Reversed" };

	int algoIndex = -1;
	for (int i = 0; i < sizeof(sortT) / sizeof(sortT[0]); i++) {
		if (algo == sortT[i]) {
			algoIndex = i;
			break;
		}
	}

	if (algoIndex == -1) {
		cerr << "Algorithm not found " << algo << endl;
		return;
	}

	cout << "Algorithm: " << sortT[algoIndex] << endl;
	cout << "Input size: " << size << endl;
	cout << endl;

	for (int i = 0; i < 4; i++) {
		cout << "Input order: " << orders[i] << endl;
		cout << "------------------------------------" << endl;
	
		int a[MAX];
		GenerateData(a, size, i);
		if (i == 0)
		{
			printFile(a, size, "input_1.txt");
		}
		if (i == 1)
		{
			printFile(a, size, "input_2.txt");
		}
		if (i == 2)
		{
			printFile(a, size, "input_3.txt");
		}
		if (i == 3)
		{
			printFile(a, size, "input_4.txt");
		}
		
		int b[MAX];
		duplicateArray(a, size, b, size);
		int64_t compare = 0;
		double time = 0;

		if (para != "-both" && para != "-time" && para != "-comp") {
			cout << "Invalid parameter" << endl;
			return;
		}

		if (para == "-both" || para == "-time") {
			auto start = chrono::high_resolution_clock::now();
			runSortingAlgorithmWithTime(a, size, algoIndex);
			auto end = chrono::high_resolution_clock::now();
			chrono::duration<double, milli> duration = end - start;
			time = duration.count();
		}

		if (para == "-both" || para == "-comp") {
			compare = runSortingAlgorithmWithCompare(b, size, algoIndex, compare);
		}

		if (para == "-time" || para == "-both") {
			cout << "Running time: " << time << " ms" << endl;
		}

		if (para == "-comp" || para == "-both") {
			cout << "Comparisons: " << compare << endl;
		}
	}
}

void command4(string algo1, string algo2, string file) {
	string sortT[12] = { "selection-sort", "insertion-sort", "shell-sort", "bubble-sort", "heap-sort", "merge-sort", "quick-sort", "radix-sort", "counting-sort", "binary-insertion-sort", "shaker-sort", "flash-sort" };

	cout << "Algorithm: " << algo1 << " | " << algo2 << endl;
	int algo1_Index = -1;
	int algo2_Index = -1;
	for (int i = 0; i < sizeof(sortT) / sizeof(sortT[0]); i++) {
		if (algo1 == sortT[i]) {
			cout << sortT[i] << endl;
			algo1_Index = i;
		}
		if (algo2 == sortT[i]) {
			cout << sortT[i] << endl;
			algo2_Index = i;
		}
	}

	if (algo1_Index == -1 || algo2_Index == -1) {
		cerr << "Algorithm not found" << endl;
		return;
	}

	int a[MAX], b[MAX];
	int c[MAX], d[MAX];
	int n = 0;

	readFile(a, n, file);
	if (n == 0) {
		cerr << "Failed to read input file or file is empty" << endl;
		return;
	}

	duplicateArray(a, n, b, n);
	duplicateArray(a, n, c, n);
	duplicateArray(a, n, d, n);
	cout << "Input file: " << file << endl;
	cout << "Input size: " << n << endl;
	cout << "------------------" << endl;

	int64_t compare1 = 0, compare2 = 0;
	double time1 = 0, time2 = 0;

	auto start1 = chrono::high_resolution_clock::now();
	runSortingAlgorithmWithTime(a, n, algo1_Index);
	auto end1 = chrono::high_resolution_clock::now();
	chrono::duration<double, milli> duration1 = end1 - start1;
	time1 = duration1.count();

	auto start = chrono::high_resolution_clock::now();
	runSortingAlgorithmWithTime(b, n, algo2_Index);
	auto end = chrono::high_resolution_clock::now();
	chrono::duration<double, milli> duration = end - start;
	time2 = duration.count();

	compare1 = runSortingAlgorithmWithCompare(c, n, algo1_Index, compare1);
	compare2 = runSortingAlgorithmWithCompare(d, n, algo2_Index, compare2);

	cout << "Time: " << time1 << " | " << time2 << endl;
	cout << "comparisons: " << compare1 << " | " << compare2 << endl;
}

void command5(string algo1, string algo2, string size, string order) {
	string sortT[12] = { "selection-sort", "insertion-sort", "shell-sort", "bubble-sort", "heap-sort", "merge-sort", "quick-sort", "radix-sort", "counting-sort", "binary-insertion-sort", "shaker-sort", "flash-sort" };

	int algo1_Index = -1;
	int algo2_Index = -1;

	for (int i = 0; i < sizeof(sortT) / sizeof(sortT[0]); i++) {
		if (algo1 == sortT[i]) {
			algo1_Index = i;
		}
		if (algo2 == sortT[i]) {
			algo2_Index = i;
		}
	}

	if (algo1_Index == -1 || algo2_Index == -1) {
		cerr << "Algorithm not found" << endl;
		return;
	}
	cout << "Algorithm: " << algo1 << " | " << algo2 << endl;

	int a[MAX], b[MAX];
	if (!isInteger(size)) {
		cout << "Invalid input size" << endl;
		return;
	}
	int n = stoi(size);
	if (n > 1000000) {
		cout << "oversize" << endl;
		return;
	}

	cout << "Input size: " << n << endl;

	if (order == "-rand") {
		cout << "Input order: randomized data" << endl;
		GenerateData(a, n, 0);
	}
	else if (order == "-sorted") {
		cout << "Input order: sorted data" << endl;
		GenerateData(a, n, 2);
	}
	else if (order == "-rev") {
		cout << "Input order: reversed data" << endl;
		GenerateData(a, n, 3);
	}
	else if (order == "-nsorted") {
		cout << "Input order: nearly sorted data" << endl;
		GenerateData(a, n, 1);
	}
	else {
		cerr << "Invalid input order" << endl;
		return;
	}
	printFile(a, n, "input.txt");
	int c[MAX], d[MAX];
	duplicateArray(a, n, b, n);
	duplicateArray(a, n, c, n);
	duplicateArray(a, n, d, n);

	int64_t compare1 = 0, compare2 = 0;
	double time1 = 0, time2 = 0;

	auto start1 = chrono::high_resolution_clock::now();
	runSortingAlgorithmWithTime(a, n, algo1_Index);
	auto end1 = chrono::high_resolution_clock::now();
	chrono::duration<double, milli> duration1 = end1 - start1;
	time1 = duration1.count();

	auto start2 = chrono::high_resolution_clock::now();
	runSortingAlgorithmWithTime(b, n, algo2_Index);
	auto end2 = chrono::high_resolution_clock::now();
	chrono::duration<double, milli> duration2 = end2 - start2;
	time2 = duration2.count();

	compare1 = runSortingAlgorithmWithCompare(c, n, algo1_Index, compare1);
	compare2 = runSortingAlgorithmWithCompare(d, n, algo2_Index, compare2);

	cout << "Time: " << time1 << " ms | " << time2 << " ms" << endl;
	cout << "Comparisons: " << compare1 << " | " << compare2 << endl;
}

bool isInteger(const string& str) {
	if (str.empty()) {
		return false;
	}

	size_t start = 0;
	if (str[0] == '-' || str[0] == '+') {
		start = 1;
	}

	if (start == str.size()) {
		return false;  // The string only contains a sign
	}

	for (size_t i = start; i < str.size(); ++i) {
		if (!isdigit(str[i])) {
			return false;
		}
	}

	return true;
}
