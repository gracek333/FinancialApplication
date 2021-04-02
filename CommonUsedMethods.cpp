#include "CommonUsedMethods.h"
#include <algorithm>

string CommonUsedMethods :: getPhrase()
{
    string phrase = "";
    getline(cin, phrase);
    return phrase;
}

char CommonUsedMethods :: getChar()
{
    string inputData = "";
    char character = {0};

    while (true)
    {
        getline(cin, inputData);
        if (inputData.length() == 1)
        {
            character = inputData[0];
            break;
        }
        cout << "To nie jest pojedynczy znak. Wpisz ponownie." << endl;
    }
    return character;
}

string CommonUsedMethods :: convertIntIntoString(int number)
{
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}
