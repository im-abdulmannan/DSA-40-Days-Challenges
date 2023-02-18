#include <iostream>
using namespace std;

int countWord(string str)
{
    int count = 0;
    bool word = false;

    for (char c : str)
    {
        if (c == ' ' && word)
        {
            count++;
            word = false;
        }
        else if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        {
            word = true;
        }
    }

    if (word)
    {
        count++;
    }
    return count;
}

int main(void)
{
    string strcing = "Hello, !   World  ";
    cout << countWord(strcing);

    return 0;
}