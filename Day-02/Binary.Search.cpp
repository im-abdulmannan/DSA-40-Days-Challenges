#include <iostream>
using namespace std;

int binarySearch(int array[], int targetNum, int left, int right)
{

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (array[mid] == targetNum)
        {
            return mid;
        }
        else if (array[mid] < targetNum)
        {
            left = mid + 1;
        }

        else if (array[mid] > targetNum)
        {
            right = mid - 1;
        }
    }

    return 0;
}

int main()
{
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int targetNum = 8;
    int sizeOfArray = sizeof(array) / sizeof(array[0]);
    int result = binarySearch(array, targetNum, 0, sizeOfArray - 1);
    if (result == 0)
        cout << "Not found";
    else
        cout << "Element is found at index " << result;

    return 0;
}