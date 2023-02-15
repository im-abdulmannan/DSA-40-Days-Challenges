#include <iostream>
using namespace std;

void FindIndexOfChar(string str, char character)
{
    for (int index = 0; index < str.length(); index++)
    {
        if (str[index] == character)
        {
            cout << index << " ";
        }
    }
};

int main()
{
    string word = "Facebook";
    char chr = 'c';
    FindIndexOfChar(word, chr);
    return 0;
}