#ifndef COMMONUSEDMETHODS_H
#define COMMONUSEDMETHODS_H

#include <sstream>
#include <iostream>
#include <vector>
#include <windows.h>

using namespace std;

class CommonUsedMethods
{
public:

    static string getPhrase();
    static char getChar();
    static string convertIntIntoString(int number);
    static int convertStringIntoInt(string numberInString);
    static float getFloatFromUser();
    static bool isNumberFromUserCorrect(string inputData);
    static string replaceCommaWithDot(string inputData);
    static float convertStringToFloat(string inputDataWithDot);

};

#endif
