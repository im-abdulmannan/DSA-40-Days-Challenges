#include <iostream>
using namespace std;

class Solution
{
public:
    // Recursive approach for fibonacci
    int RecursiveFibonacci(int n)
    {
        if (n <= 1)
            return n;

        return RecursiveFibonacci(n - 1) + RecursiveFibonacci(n - 2);
    }

    // Iterative approach for fibonacci
    int IterativeFibonacchi(int n)
    {
        int previousNumber = 0, currentNumber = 1, lastPreviousNumber;

        for (int i = 1; i < n; i++)
        {
            lastPreviousNumber = previousNumber;
            previousNumber = currentNumber;
            currentNumber = previousNumber + lastPreviousNumber;
        }

        return currentNumber;
    }
};

int main(void)
{
    Solution S;
    int n = 10;
    cout << "Fibonacci of " << n << " by Iterative approach = " << S.IterativeFibonacchi(n);
    cout << "\nFibonacci of " << n << " by Recursive approach = " << S.RecursiveFibonacci(n);

    return 0;
}