#ifndef COMMANDLINE_H
#define COMMANDLINE_H

#include "Lib.h"
#include "DataGenerator.h"
#include "SortWithCompare.h"
#include "SortWithTime.h"

int64_t runSortingAlgorithmWithCompare(int a[], int n, int i, int64_t& compare);
void runSortingAlgorithmWithTime(int a[], int n, int i);
void command1(string algo, string file, string para);
void command2(string algo, string inputSize, string inputOrder, string para);
void command3(string algo, string sizeStr, string para);
void command4(string algo1, string algo2, string file);
void command5(string algo1, string algo2, string size, string order);
bool isInteger(const string& str);
#endif