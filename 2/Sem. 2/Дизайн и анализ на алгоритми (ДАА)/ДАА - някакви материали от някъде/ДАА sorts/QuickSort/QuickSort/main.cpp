#include <iostream>
#include <vector>

void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

int Partition(std::vector<int>& arr, int start, int end)
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

void QuickSort(std::vector<int>& arr, int start, int end)
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
	std::vector<int> arr = { 1, 10, -3, 5, 0, -7, 15, 18, 9, -4 };
	QuickSort(arr, 0, arr.size() - 1);
	for (int i = 0; i < arr.size(); i++)
	{
		std::cout << arr[i] << " ";
	}
	return 0;
}