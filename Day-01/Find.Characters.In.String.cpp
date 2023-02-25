#include <iostream>
#include <string>
#include <vector>
using namespace std;

int findCharacterInString(string word, char character)
{
    for (int index = 0; index < word.length(); index++)
    {
        if (word[index] == character)
        {
            return index;
        }
    }
    return -1;
};

vector<int> findAllCharacterOfAString(string word, char character)
{
    vector<int> chr;
    for (int index = 0; index < word.length(); index++)
    {
        if (word[index] == character)
        {
            chr.push_back(index);
        }
    }
    return chr;
};

int main()
{
    string word = "hello";
    char chr = 'l';
    cout << "Find Character Index in Array:: ";
    findCharacterInString(word, chr);
    cout << "Find All Character Indexes in Array:: ";
    findAllCharacterOfAString(word, chr);
    return 0;
}