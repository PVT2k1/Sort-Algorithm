#pragma once

#include <iostream>
#include <cmath>
#include <time.h>

using namespace std;

template <class T>
void HoanVi(T& a, T& b)
{
	T x = a;
	a = b;
	b = x;
}

#pragma comment(linker, "/STACK:100000000000")

//-------------------------------------------------

// Hàm phát sinh mảng dữ liệu ngẫu nhiên
void GenerateRandomData(int* a, int n);

// Hàm phát sinh mảng dữ liệu có thứ tự tăng dần
void GenerateSortedData(int* a, int n);

// Hàm phát sinh mảng dữ liệu có thứ tự nguợc (giảm dần)
void GenerateReverseData(int* a, int n);

// Hàm phát sinh mảng dữ liệu gần như có thứ tự
void GenerateNearlySortedData(int* a, int n);

//chọn kiểu dữ liệu mảng đầu vào mà bạn muốn
void GenerateData(int* a, int n, int dataType);

//chọn kích cỡ dữ liệu đầu vào: 3,000; 10,000; 30, 000; 100, 000; 300, 000.
void GenerateDatasize(int& n, int dataSizeType);

// chọn kiểu sort và sắp xếp ngay tại hàm này
void GenerateSort(int* a, int n, int typeSort);

//---------------BUBBLE SORT---------------------
void BubbleSort(int* a, int n);

//---------------INSERTION SORT---------------------
void insertionSort(int* a, int n);

//---------------SELECTION SORT---------------------
void selectionSort(int* a, int n);

//---------------BINARY-INSERTION SORT---------------------

//hàm trả về vị trí hay chỉ số mà item sẽ được chèn vào trong 1 mảng đã sắp xếp
int binarySearch(int* a, int item, int left, int right);

//hàm chính của binary_InsertionSort
void binary_InsertionSort(int* a, int n);

//---------------HEAP SORT---------------------

//hàm tạo lại heapsort theo nhánh bị mất cân bằng tại node thứ i
void heapify(int* a, int n, int i);

//hàm chính của heapsort
void heapSort(int* a, int n);

//----------------QUICK SORT-----------------------

void quickSort(int* a, int l, int r);

//------------MERGER SORT-----------------------

// thực hiện merge sort với 2 mảng
void merge(int* a, int l, int mid, int r);

void merge_sort(int* a, int l, int r);