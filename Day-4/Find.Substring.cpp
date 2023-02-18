#include <iostream>
#include <string>
using namespace std;

void findSubString(string input, string word)
{
    int length = word.length();
    int index = -1;

    for (int i = 0; i < input.length() - length + 1; i++)
    {
        if (input[i] == word[0])
        {
            int j = i;
            int found = 0;

            while (j < i + length && input[j] == word[j - i])
            {
                found++;
                j++;
            }
            if (found == length)
            {
                index = i;
            }
        }
    }

    if (index != -1)
    {
        cout << "The Word " << word << "is found at Index " << index << ".";
    }
    else
    {
        cout << "Match Not Found!";
    }
};

int main(void)
{
    string str = "This is Abdul Mannan from University of Education";
    string word = "University";

    findSubString(str, word);

    return 0;
}