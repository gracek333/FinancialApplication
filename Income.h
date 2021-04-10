#ifndef INCOME_H
#define INCOME_H

#include <iostream>

using namespace std;

class Income
{
    int incomeId, userId;
    long int date;
    float amount;
    string item;

public:
    void setIncomeId(int newId);
    void setUserId(int newUserId);
    void setDate(long int newDate);
    void setItem(string newItem);
    void setAmount(float newAmount);

    int getIncomeId();
    int getUserId();
    long int getDate();
    string getItem();
    float getAmount();
};

#endif
