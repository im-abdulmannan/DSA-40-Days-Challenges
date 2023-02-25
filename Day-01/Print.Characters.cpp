#include <iostream>
#include <string>
using namespace std;
int PrintCharactersInString(string word)
{
    for (int index = 0; index < word.length(); index++)
    {
        cout << word[index] << endl;
    }
    return -1;
};

int main()
{
    string word = "Hello World";
    PrintCharactersInString(word);
    return 0;
}