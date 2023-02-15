#include <iostream>
using namespace std;

bool isPrimeNumber(int n)
{
    for (int i = 0; i < n / 2; i++)
    {
        if (n % 2 != 0)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    int n = 12;
    isPrimeNumber(n);
    if (isPrimeNumber(n) == true)
    {
        cout << "Prime";
    }
    else
    {
        cout << "Not Prime";
    }
    return 0;
}