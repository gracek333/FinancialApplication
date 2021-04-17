#ifndef DATEMANAGER_H
#define DATEMANAGER_H

#include <sstream>
#include <iostream>
#include <vector>
#include <windows.h>
#include <string>
#include <ctime>
#include <cstdlib>

#include "Date.h"

using namespace std;

class DateManager
{

public:
    static int convertDateToIntForVector(Date date);
    static Date getDateFromSystem();
    static Date getDateFromUser();
    static Date convertDateFromUserToStructure(string dateFromUser);
    static int getYearFromDateInString(string dateFromUser);
    static int getMonthFromDateInString(string dateFromUser);
    static int getDayFromDateInString(string dateFromUser);
    static bool isDateCorrect(string date);
    static bool isDateFormatCorrect(string date);
    static bool isDateExisting(string date);
    static bool checkExistingOfDate(Date dateFromUser);
    static int returnTotalNumberOfDaysInMonth(int year, int month);
    static string convertDateInIntToString(int dateInInt);
    static Date convertDateFromIntToStructure(int dateInInt);
    static string convertDateToString(Date date);
    static string doAddZero(string monthOrDay);
    static Date getLastDateForPreviousMonth();

};


#endif
