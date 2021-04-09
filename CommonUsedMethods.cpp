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

int CommonUsedMethods :: convertStringIntoInt(string numberInString)
{
    int number = 0;
    number = atof(numberInString.c_str());
    return number;
}

float CommonUsedMethods :: getFloatFromUser()
{
    string inputData = "";
    string inputDataWithDot = "";
    float number = 0.0;
    while (true)
    {
        getline(cin, inputData);
        if (isNumberFromUserCorrect(inputData))
        {
            break;
        }
        cout << "Wpisz date w odpowiednim formacie, bez spacji i innych znakow bialych" << endl << "poza kropka lub przecinkiem! :  ";
    }
    inputDataWithDot = replaceCommaWithDot(inputData);
    number = convertStringToFloat(inputDataWithDot);

    return number;
}

bool CommonUsedMethods :: isNumberFromUserCorrect(string inputData)
{
    int amountOfDots = 0;
    for (int i = 0; i < inputData.length(); i++)
    {
        if (inputData[i] == ',' || inputData[i] == '.')
        {
            amountOfDots++;
        }

        if (   !(isdigit(inputData[i])   ||  inputData[i] == ',' || inputData[i] == '.' ) || amountOfDots > 1)
        {
            return false;
        }

    }
    return true;
}

string CommonUsedMethods :: replaceCommaWithDot(string inputData)
{
    for (int i = 0; i < inputData.length(); i++)
    {
        if (inputData[i] == ',')
        {
            inputData[i] = '.';
            return inputData;
        }
    }
    return inputData;
}

float CommonUsedMethods :: convertStringToFloat(string inputDataWithDot)
{
    float number = 0.0;
    number = atof(inputDataWithDot.c_str());
    return number;
}
