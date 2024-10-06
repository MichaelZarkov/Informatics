#include <iostream>
#include <vector>

void ShellSort(std::vector<int>& arr, int n)
{
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i++)
        {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
            {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

int main()
{
    std::vector<int> arr = { 36, 14, 435, 6, 43, 1, 53, -45, 0, 65 };
    ShellSort(arr, arr.size());
    for (int i = 0; i < arr.size(); i++)
    {
        std::cout << arr[i] << " ";
    }
	return 0;
}