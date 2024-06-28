#include "DataGenerator.h"
#include "SortWithCompare.h"
#include "SortWithTime.h"
#include "CommandLine.h"

//cm 2: -a counting-sort 1000000 -rand -both
//cm 1: -a flash-sort input.txt -both
//cm 3: -a merge-sort 500000 -time
//cm 4: -c flash-sort quick-sort input.txt
//cm 5: -c merge-sort heap-sort 500000 -rev

int main(int argc, char* argv[])
{
	if (argc < 5) 
	{
		cout << "Usage: " << argv[0] << " -a|-c [Algorithm] [Input filename]|[input Size] [Output parameter(s)]" << endl;
		return 1;
	}
	if (string(argv[1]) == "-a") 
	{
		cout << "ALGORITHM MODE" << endl;
		if (argc == 5) 
		{
			if (isInteger(argv[3])) 
			{
				string algo = argv[2];
				string inputSize = argv[3];
				string para = argv[4];
				command3(algo, inputSize, para);
				return 1;
			}
			string algo = argv[2];
			string file = argv[3];
			string para = argv[4];

			command1(algo, file, para);
			return 1;
		}

		string algo = argv[2];
		string inputSize = argv[3];
		string inputOrder = argv[4];
		string para = argv[5];
		command2(algo, inputSize, inputOrder, para);
		return 1;

	}
	else if (string(argv[1]) == "-c") {
		cout << "COMPARISON MODE" << endl;
		if (argc == 5) {
			string algo1 = argv[2];
			string algo2 = argv[3];
			string file = argv[4];
			command4(algo1, algo2, file);
			return 1;
		}
		else
		{
			string algo1 = argv[2];
			string algo2 = argv[3];
			string size = argv[4];
			string order = argv[5];
			command5(algo1, algo2, size, order);
			return 1;
		}
	}
	cout << "Wrong flags, please input again.";
	return 0;
}
