#include <bits/stdc++.h>

using namespace std;

string trimfnc(string str)
{
    int fromStart = 0, fromEnd = str.length() - 1;

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] != ' ')
        {
            fromStart = i;
            break;
        }
    }
    
    for (int i = str.length() - 1; i >= 0; i--)
    {
        if (str[i] != ' ')
        {
            fromEnd = i;
            break;
        }
    }
    string fistr = "";
    for (int i = fromStart; i <= fromEnd; i++)
    {
        fistr += str[i];
    }
    return fistr;
}

int main()
{
    string str = "   Hello world    ";
    // getline(cin, str);
    cout << trimfnc(str);
}