#ifndef EXPENSESFILE_H
#define EXPENSESFILE_H

#include <iostream>
#include <vector>
#include <fstream>

#include "Expense.h"

using namespace std;

class ExpensesFile
{
    const string EXPENSES_FILE_NAME;
    int lastExpenseId;

    void setLastExpenseId(int newLastExpenseId);

public:
    ExpensesFile(string expensesFileName) : EXPENSES_FILE_NAME(expensesFileName) {lastExpenseId = 0;};
    string getExpensesFileName();
    vector <Expense> getExpensesOfLoggedUserFromFile(int loggedInUserId);
    void addExpenseToFile(Expense expense);
    int getLastExpenseId();
};

#endif
