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
        if (isDateExisting(date))
        {
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

    if ((dateFromUser.getYear() >= 2000) && (dateFromUser.getYear() <= 2021))
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

string DateManager :: convertDateInIntToString(int dateInInt)
{
    Date date;
    string dateInString = "";

    date = convertDateInIntToStructure(dateInInt);
    dateInString = convertDateToString(date);

    return dateInString;
}

Date DateManager :: convertDateInIntToStructure(int dateInInt)
{
    Date date;

    date.setYear(dateInInt / 10000);
    date.setMonth((dateInInt - (date.getYear() * 10000)) / 100);
    date.setDay(dateInInt - (date.getYear() * 10000) - (date.getMonth() * 100));

    return date;
}

string DateManager :: convertDateToString(Date date)
{
    string dateInString = "";
    string year, month, day;

    year = CommonUsedMethods::convertIntToString(date.getYear());
    month = addZero(CommonUsedMethods::convertIntToString(date.getMonth()));
    day = addZero(CommonUsedMethods::convertIntToString(date.getDay()));

    dateInString = year + "-" + month + "-" + day;

    return dateInString;
}

string DateManager :: addZero(string monthOrDay)
{
    if (monthOrDay.length() == 1)
    {
        monthOrDay = "0" + monthOrDay;
    }

    return monthOrDay;
}

Date DateManager :: getFinalDateOfPreviousMonth()
{
    Date date;
    date = getDateFromSystem();

    if (date.getMonth() == 1)
    {
        date.setYear(date.getYear() - 1);
        date.setMonth(12);
    }
    else
    {
        date.setMonth(date.getMonth() - 1);
    }

    date.setDay(returnTotalNumberOfDaysInMonth(date.getYear(), date.getMonth()));

    return date;
}

long int DateManager :: askUserForDateChoosing()
{
    long int date;
    char choice;

    while (true)
    {
        cout << "Czy operacja dotyczy dnia dzisiejszego? (t / n):  ";
        choice = CommonUsedMethods :: getChar();

        if(choice == 't' || choice == 'T')
        {
            date = DateManager :: convertDateToIntForVector(DateManager :: getDateFromSystem());
            return date;
            break;
        }
        else if (choice == 'n' || choice == 'N')
        {
            date = DateManager :: convertDateToIntForVector(DateManager :: getDateFromUser());
            return date;
            break;
        }
        else
        {
            cout << "Wpisales bledny znak. Sprobuj ponownie." << endl;
        }
    }
}
