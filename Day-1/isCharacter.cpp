#include <iostream>
using namespace std;
bool isCharacter(char chr)
{
    if ((chr >= 'a' && chr <= 'z') || (chr >= 'A' && chr <= 'Z'))
    {
        return true;
    }

    return false;
}

int main(void)
{
    char chr = 'Z';
    cout << isCharacter(chr);

    return 0;
}