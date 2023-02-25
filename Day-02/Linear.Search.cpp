#include <iostream>
using namespace std;

int linearSearch(int Arr[], int targetNum, int sizeofArray)
{
    for (int index = 0; index < sizeofArray; index++)
    {
        if (Arr[index] == targetNum)
        {
            return index;
        }
    }
};

int main(void)
{
    int array[] = {30, 33, 32, 34, 35, 36, 37, 38};
    int targetNum = 32;
    int sizeofArray = sizeof(array) / sizeof(array[0]);
    int result = linearSearch(array, targetNum, sizeofArray);
    cout << "Element of target number is: " << result;
    return 0;
}