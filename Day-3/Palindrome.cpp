#include <iostream>
using namespace std;

bool isPalindrome(string str)
{
    int left = 0;
    int right = str.length() - 1;

    while (left < right)
    {
        if (str[left] != str[right])
            return false;

        left++;
        right--;
    }

    return true;
};

int main(void)
{

    string input = "maham";
    isPalindrome(input);
    if (isPalindrome(input) == true)
    {
        cout << "Palindrome";
    }
    else
    {
        cout << "Not Palindrome";
    }

    return 0;
}