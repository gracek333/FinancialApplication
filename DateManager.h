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
};


#endif
