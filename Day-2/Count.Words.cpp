#include <iostream>
#include <string>
using namespace std;

bool isCharacter(string input, char character)
{
    if ((character >= 'a' && character <= 'z') || (character >= 'A' && character <= 'Z'))
    {
        return true;
    }

    return false;
};

int main()
{
    string input = "Count,  the number of words in this string";
    int wordCount = 0;
    for (int i = 0; i < input.length(); i++)
    {
        if (input[i] == ' ' || i == input.length() - 1)
        {
            wordCount++;
        }
    }

    cout << "Word count: " << wordCount << endl;
    return 0;
}