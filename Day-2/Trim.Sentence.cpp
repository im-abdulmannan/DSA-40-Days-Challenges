#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string trim_sentence(string sentence)
{
    auto start = sentence.begin();
    auto end = sentence.end() - 1;

    // Trim whitespace from the start of the sentence
    while (start < end && isspace(*start))
    {
        start++;
    }

    // Trim whitespace from the end of the sentence
    while (end > start && isspace(*end))
    {
        end--;
    }

    // Return the trimmed sentence
    return string(start, end + 1);
}

int main()
{
    string input = "    Hello World    ";
    string result = trim_sentence(input);
    cout << result;
    return 0;
}