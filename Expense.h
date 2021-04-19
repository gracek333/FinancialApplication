#ifndef EXPENSE_H
#define EXPENSE_H

#include <iostream>

using namespace std;

class Expense
{
    int expenseId, userId;
    long int date;
    float amount;
    string item;

public:
    void setExpenseId(int newId);
    void setUserId(int newUserId);
    void setDate(long int newDate);
    void setItem(string newItem);
    void setAmount(float newAmount);

    int getExpenseId();
    int getUserId();
    long int getDate();
    string getItem();
    float getAmount();

    static bool sortVectorByDatesFromTheOldest(const Expense& x, const Expense& y);

};

#endif
