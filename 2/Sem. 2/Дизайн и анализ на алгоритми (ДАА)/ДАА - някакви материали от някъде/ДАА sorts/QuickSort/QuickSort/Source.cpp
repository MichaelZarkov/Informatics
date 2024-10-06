#include <iostream>

void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

int Partition(int arr[], int start, int end)
{
	int pivotValue = arr[end];
	int pivotIndex = start;

	for (int i = start; i < end; i++)
	{
		if (arr[i] <= pivotValue)
		{
			swap(arr[pivotIndex], arr[i]);
			pivotIndex++;
		}
	}
	swap(arr[pivotIndex], arr[end]);
	return pivotIndex;
}

void QuickSort(int arr[], int start, int end)
{
	if (start >= end)
	{
		return;
	}
	int index = Partition(arr, start, end);
	QuickSort(arr, start, index - 1);
	QuickSort(arr, index + 1, end);
}

int main()
{
	int arr[10] = { 1, 10, -3, 5, 0, -7, 15, 18, 9, -4 };
	QuickSort(arr, 0, 9);
	for (int i = 0; i < 10; i++)
	{
		std::cout << arr[i] << " ";
	}
	return 0;
}