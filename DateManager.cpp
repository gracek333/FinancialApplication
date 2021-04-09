#include "DateManager.h"
#include "CommonUsedMethods.h"
#include "Date.h"
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

Date DateManager :: convertDateFromUserToStructure(string dateFromUser)
{
    Date date;

    date.setYear(getYearFromDateInString(dateFromUser));
    date.setMonth(getMonthFromDateInString(dateFromUser));
    date.setDay(getDayFromDateInString(dateFromUser));

    return date;
}

Date DateManager :: getDateFromUser()
{
    string dateFromUser = "";
    Date dateFromUserInStructure;
    cout << "Wpisz date w formacie [RRRR-MM--DD]:  ";
    while (true)
    {
        getline(cin,dateFromUser);

        if (true)//isDateCorrect(dateFromUser))
        {
            dateFromUserInStructure = convertDateFromUserToStructure(dateFromUser);
            break;
        }
        cout << "Data nieprawidlowa. Wpisz ponownie istniejaca date w poprawnym formacie np. [2021-02-28]:  ";
    }
    return dateFromUserInStructure;
}

int DateManager :: getYearFromDateInString(string dateFromUser)
{
    int year = 0;
    string yearInString = dateFromUser.substr(0,4);
    year = CommonUsedMethods :: convertStringIntoInt(yearInString);

    return year;
}

int DateManager :: getMonthFromDateInString(string dateFromUser)
{
    int month = 0;
    string monthInString = dateFromUser.substr(5.2);
    month = CommonUsedMethods :: convertStringIntoInt(monthInString);

    return month;
}

int DateManager :: getDayFromDateInString(string dateFromUser)
{
    int day = 0;
    string dayInString = dateFromUser.substr(8.2);
    day = CommonUsedMethods :: convertStringIntoInt(dayInString);

    return day;
}
