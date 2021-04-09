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

    /*int getYearFromDateInString(string dateFromUser);
    int getMonthFromDateInString(string dateFromUser);
    int getDayFromDateInString(string dateFromUser);
    //Date convertDateFromUserToStructure(string dateFromUser);*/

public:
    static int convertDateToIntForVector(Date date);
    static Date getDateFromSystem();
    static Date getDateFromUser();
    static Date convertDateFromUserToStructure(string dateFromUser);
    static int getYearFromDateInString(string dateFromUser);
    static int getMonthFromDateInString(string dateFromUser);
    static int getDayFromDateInString(string dateFromUser);

};


#endif
