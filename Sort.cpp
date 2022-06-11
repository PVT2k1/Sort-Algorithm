#include "Sort.h"

void GenerateRandomData(int* a, int n)
{
	srand((unsigned int)time(NULL));
	for (int i = 0; i < n; i++)
		a[i] = rand() % n;
}

void GenerateSortedData(int* a, int n)
{
	for (int i = 0; i < n; i++)
		a[i] = i;
}

void GenerateReverseData(int* a, int n)
{
	for (int i = 0; i < n; i++)
		a[i] = n - 1 - i;
}

void GenerateNearlySortedData(int* a, int n)
{
	for (int i = 0; i < n; i++)
		a[i] = i;
	srand((unsigned int)time(NULL));
	for (int i = 0; i < 10; i++)
	{
		int r1 = rand() % n;
		int r2 = rand() % n;
		HoanVi(a[r1], a[r2]);
	}
}

void GenerateData(int* a, int n, int dataType)
{
	switch (dataType)
	{
	case 0:	// ngẫu nhiên
		GenerateRandomData(a, n);
		cout << "Phat sinh du lieu ngau nhien\n";
		break;
	case 1:	// có thứ tự
		cout << "Phat sinh du lieu co thu tu\n";
		GenerateSortedData(a, n);
		break;
	case 2:	// có thứ tự ngượcc
		cout << "Phat sinh du lieu co thu tu nguoc\n";
		break;
	case 3:	// gần như có thứ tự
		cout << "Phat sinh du lieu gan nhu co thu tu\n";
		break;
	default:
		cout << "Error: unknown data type!\n";
	}
}

void GenerateDatasize(int& n, int dataSizeType)
{
	switch (dataSizeType)
	{
	case 0:	
		n = 3000;
		break;
	case 1:	
		n = 10000;
		break;
	case 2:
		n = 30000;
		break;
	case 3:	
		n = 100000;
		break;
	case 4:	
		n = 300000;
		break;
	default:
		cout << "Error: unknown dataSize type!\n";
	}
}

void GenerateSort(int* a, int n, int typeSort)
{
	clock_t start, end;
	switch (typeSort)
	{
	case 0:	// Bubble sort
		start = clock();
		BubbleSort(a, n);
		end = clock();
		cout<<"Thoi gian thuc hien BUBBLE SORT cho du lieu kich co " << n << "la: "<<((double)end-start) / CLOCKS_PER_SEC <<endl;
		break;
	case 1:	// Insertion sort 
		start = clock();
		insertionSort(a, n);
		end = clock();

		cout << "Thoi gian thuc hien INSERTION SORT cho du lieu kich co " << n << "la: " << ((double)end - start) / CLOCKS_PER_SEC << endl;
		break;
	case 2:	// Selection sort 
		start = clock();
		selectionSort(a, n);
		end = clock();
		cout << "Thoi gian thuc hien SELECTION SORT cho du lieu kich co " << n << "la: " << ((double)end - start) / CLOCKS_PER_SEC << endl;
		break;
	case 3:	//binary InsertionSort
		start = clock();
		binary_InsertionSort(a, n);
		end = clock();
		cout << "Thoi gian thuc hien BINARY INSERTION SORT cho du lieu kich co " << n << "la: " << ((double)end - start) / CLOCKS_PER_SEC << endl;
		break;
	case 4:	//heap Sort
		start = clock();
		heapSort(a, n);
		end = clock();
		cout << "Thoi gian thuc hien HEAP SORT cho du lieu kich co " << n << "la: " << ((double)end - start) / CLOCKS_PER_SEC << endl;
		break;
	case 5:	//quick Sort
		start = clock();
		quickSort(a, 0, n-1);
		 end = clock();
		cout << "Thoi gian thuc hien QUICK SORT cho du lieu kich co " << n << "la: " << ((double)end - start) / CLOCKS_PER_SEC << endl;
		break;
	case 6:	//merger Sort
		start = clock();
		merge_sort(a, 0, n-1);
		end = clock();
		cout << "Thoi gian thuc hien MERGER SORT cho du lieu kich co " << n << "la: " << ((double)end - start) / CLOCKS_PER_SEC << endl;
		break;
	default:
		cout << "Error: unknown type Sort!\n";
	}
}

//------------------------------------------------
void BubbleSort(int* a, int n)
{
	for (int i = 0; i < n - 1; i++) 
	{
		// i phần tử cuối cùng đã được sắp xếp
		bool haveSwap = false;
		for (int j = 0; j < n - i - 1; j++)
		{
			if (a[j] > a[j + 1]) 
			{
				HoanVi(a[j], a[j + 1]);
				haveSwap = true; 
			}
		}
		if (haveSwap == false)
			break;
	}
}

//------------------------------------------------
void insertionSort(int* a, int n)
{
	for (int i = 1; i < n; i++)
	{
		int key = a[i];
		int  j = i - 1;

		/* Di chuyển các phần tử có giá trị lớn hơn giá trị
		key về sau một vị trí so với vị trí ban đầu
		của nó */
		while (j >= 0 && a[j] > key)
		{
			a[j + 1] = a[j];
			j = j - 1;
		}
		a[j + 1] = key;
	}
}

//------------------------------------------------
void selectionSort(int* a, int n)
{
	// Di chuyển ranh giới của mảng đã sắp xếp và chưa sắp xếp
	for (int i = 0; i < n - 1; i++)
	{
		int min_idx = i;
		for (int j = i + 1; j < n; j++)
			if (a[j] < a[min_idx])
				min_idx = j;
		HoanVi(a[i], a[min_idx]);
	}
}

//------------------------------------------------
int binarySearch(int* a, int item, int left, int right)
{
	if (right <= left)
		return (item > a[left]) ? (left + 1) : left;

	int mid = (left + right) / 2;

	if (item == a[mid])
		return mid + 1;

	if (item > a[mid])
		return binarySearch(a, item, mid + 1, right);
	return binarySearch(a, item, left, mid - 1);
}

void binary_InsertionSort(int* a, int n)
{
	for (int i = 1; i < n; ++i)
	{
		int j = i - 1;
		int selected = a[i];

		int location = binarySearch(a, selected, 0, j);

		// Move all elements after location to create space
		while (j >= location)
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = selected;
	}
}


//------------------------------------------------
void heapify(int* a, int n, int i)
{
	int largest = i;
	int subLeft = 2 * i + 1;
	int subright = 2 * i + 2;
	if (subLeft < n && a[subLeft] > a[largest])
		largest = subLeft;

	if (subright < n && a[subright] > a[largest])
		largest = subright;

	if (largest != i)
	{
		HoanVi(a[i], a[largest]);
		heapify(a, n, largest);
	}
}

void heapSort(int* a, int n)
{
	//xây heap sort lần đầu tiên
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(a, n, i);

	for (int i = n - 1; i > 0; i--)
	{
		HoanVi(a[0], a[i]);
		heapify(a, i, 0);
	}
}

//------------------------------------------------
void quickSort(int* a, int l, int r) {
	int p = a[(l + r) / 2];
	int i = l, j = r;
	while (i < j) {
		while (a[i] < p) {
			i++;
		}
		while (a[j] > p) {
			j--;
		}
		if (i <= j) {
			int temp = a[i];
			a[i] = a[j];
			a[j] = temp;
			i++;
			j--;
		}
	}
	if (i < r) {
		quickSort(a, i, r);
	}
	if (l < j) {
		quickSort(a, l, j);
	}
}

//-------------------------------------------------
void merge(int* a, int l, int mid, int r)
{
	int left1 = l, right1 = mid, left2 = mid + 1, right2 = r;
	int* temp = new int[r-l+10];
	int index = 0;
	while ((left1 <= right1) && (left2 <= right2)) {
		if (a[left1] <= a[left2]) {
			temp[index] = a[left1];
			++index;
			++left1;
		}
		else {
			temp[index] = a[left2];
			++index;
			++left2;
		}
	}
	while (left1 <= right1) {
		temp[index] = a[left1];
		++index;
		++left1;
	}
	while (left2 <= right2) {
		temp[index] = a[left2];
		++index;
		++left2;
	}
	--index;
	for (int i = r; i >= l; i--) {
		a[i] = temp[index];
		--index;
	}
	delete[] temp;
	temp = nullptr;
}

void merge_sort(int* a, int l, int r) {
	if (l < r) {
		int mid = (l + r - 1) / 2;
		merge_sort(a, l, mid);
		merge_sort(a, mid + 1, r);
		merge(a, l, mid, r);
	}
}