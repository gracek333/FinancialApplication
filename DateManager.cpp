#include "DateManager.h"
#include <algorithm>

int DateManager :: convertDateToIntForVector(Date date)
{
    int dataInInt = 0;

    dataInInt = (date.getYear()*10000)+(date.getMonth()*100)+date.getDay();

    return dataInInt;
}

Date DateManager :: getDateFromSystem()
{
    Date date;

    time_t t = time(0);
    tm* now = localtime(&t);

    date.setYear(now->tm_year + 1900);
    date.setMonth(now->tm_mon + 1);
    date.setDay(now->tm_mday);

    return date;
}

Date DateManager :: getDateFromUser()
{

}
