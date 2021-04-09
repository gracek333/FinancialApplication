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
    cout << "Wpisz date w formacie [RRRR-MM-DD]:  ";
    while (true)
    {
        getline(cin,dateFromUser);

        if (isDateCorrect(dateFromUser))
        {
            dateFromUserInStructure = convertDateFromUserToStructure(dateFromUser);
            break;
        }
        cout << "Data nieprawidlowa. Wpisz ponownie istniejaca date w poprawnym formacie " << endl << "np. 2021-02-28   :  ";
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

bool DateManager :: isDateCorrect(string date)
{
    if (isDateFormatCorrect(date))
    {
        cout << "poprawny format daty: " << date << endl;

        if (isDateExisting(date))
        {
             cout << "poprawna Date: " << date << endl;
             return true;
        }

    }
    return false;
}

bool DateManager :: isDateFormatCorrect(string date)
{
    bool isFormatCorrect = true;
    if (date.length() != 10)
    {
        isFormatCorrect = false;
        return isFormatCorrect;
    }

    for (int i = 0; i < 10; i++)
    {
        if ((i == 4) ||  (i == 7))
        {
            if (!(date[i] == '-'))
            {
                isFormatCorrect = false;
                return isFormatCorrect;
            }
        }
        else
        {
            if (!isdigit(date[i]))
            {
                isFormatCorrect = false;
                return isFormatCorrect;
            }
        }
    }
    return isFormatCorrect;
}

bool DateManager :: isDateExisting(string date)
{
    Date dateFromUser;
    dateFromUser = convertDateFromUserToStructure(date);

    bool isDateCorrect = false;
    bool isDateExisting = false;
    int year, month, day;

    if ((dateFromUser.getYear() >= 2000) && (dateFromUser.getYear() <= 2020))
    {
        if ((dateFromUser.getMonth() >= 1) && (dateFromUser.getMonth() <= 12))
        {
            isDateCorrect = true;
            isDateExisting = checkExistingOfDate(dateFromUser);
        }
    }

    return isDateCorrect*isDateExisting;
}

bool DateManager :: checkExistingOfDate(Date dateFromUser)
{
    bool isDateExisting = false;

    int totalNumberOfDaysInMonth = returnTotalNumberOfDaysInMonth(dateFromUser.getYear(), dateFromUser.getMonth());
    if ((dateFromUser.getDay() > 0) && (dateFromUser.getDay() <= totalNumberOfDaysInMonth))
    {
        isDateExisting = true;
    }

    return isDateExisting;
}

int DateManager :: returnTotalNumberOfDaysInMonth(int year, int month)
{
    int numberOfDaysInMonth = 0;
    if (month == 2)
    {
        if ((year%400 == 0) || ((year%4 == 0) && (year%100 != 0)))
        {
            numberOfDaysInMonth = 29;
        }
        else
            numberOfDaysInMonth = 28;
    }
    else if (month == 1 || month == 3 || month == 5 || month == 8 || month == 10 || month ==12)
        numberOfDaysInMonth = 31;
    else
        numberOfDaysInMonth = 30;

    return numberOfDaysInMonth;
}
