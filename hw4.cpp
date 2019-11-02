//Author: Christopher Fong
//File: hw4.cpp
//Date: 2/21/2019

#include <iostream>

using namespace std;

void print(int * a, int s);

void mergeSort(int * a, int start, int end);

void merge(int * a, int start, int mid, int end);

int main()
{
	int size = 0;

	cout << "Number of Elements in array: ";
	cin >> size;

	int * arr = nullptr;
	arr = new int[size];

	cout << "Enter your integer values for array:\n";
	for(int i = 0; i < size; i++)
	{
		int in;
		cin >> in;
		arr[i] = in;
	}

	cout << "\nInitial Array: ";
	print(arr, size);

	cout << "\n\nMerge Sorting...\n";
	mergeSort(arr, 0, size - 1);

	cout << "\nSorted Array: ";
	print(arr, size);
	cout << "\n";

	delete [] arr;

	return 0;
}

void print(int * a, int s)
{
	for (int i = 0; i < s; i++)
		cout << a[i] << " ";
}

void mergeSort(int * a, int start, int end)
{
	if (start < end)
	{
		//find the middle
		int mid = (start + end) / 2;

		//mergeSort the left side
		mergeSort(a, start, mid);

		//mergeSort the right side
		mergeSort(a, mid + 1, end);

		//merge back together
		merge(a, start, mid, end);
	}
	
}

void merge(int * a, int start, int mid, int end)
{
	//temp array
	int * temp = nullptr;
	temp = new int[end - start + 1];

	//counters
	int s = start;
	int m = mid + 1;
	int count = 0;

	//Look through both arrays and add smaller to temp
	while (s <= mid && m <= end)
	{
		if (a[s] <= a[m])
		{
			temp[count] = a[s];
			count++;
			s++;
		}
		else
		{
			temp[count] = a[m];
			count++;
			m++;
		}
	}

	//add left elements in the first interval
	while (s <= mid)
	{
		temp[count] = a[s];
		count++;
		s++;
	}

	//add left elements in the second interval
	while (m <= end)
	{
		temp[count] = a[m];
		count++;
		m++;
	}

	//copy temp array into original array
	for (int i = start; i <= end; i++) 
	{
		a[i] = temp[i - start];
	}

	delete [] temp;
}