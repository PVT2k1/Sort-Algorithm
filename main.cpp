
#include "Sort.h"

int main()
{
	int* a = new int[1000000];
	int n, datatype, dataSizeType, sortType;
	for (dataSizeType = 0; dataSizeType <= 4; dataSizeType++)
	{
		GenerateDatasize(n, dataSizeType);
		for (datatype = 0; datatype <= 3; datatype++)
			for (sortType = 0; sortType <= 6; sortType++)
			{
				GenerateData(a, n, datatype);
				GenerateSort(a, n, sortType);
			}
	}
	delete[] a;
	a = nullptr;
}