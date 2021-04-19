#ifndef FINANCESMANAGER_H
#define FINANCESMANAGER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <sstream>
#include <algorithm>

#include "Income.h"
#include "Expense.h"
#include "IncomesFile.h"
#include "ExpensesFile.h"

using namespace std;

class FinancesManager
{
    const int LOGGED_IN_USER_ID;
    vector <Income> incomes;
    vector <Expense> expenses;

    IncomesFile incomesFile;
    ExpensesFile expensesFile;

    int getIdForNewIncome();
    Income inputNewIncomeData();

    int getIdForNewExpense();
    Expense inputNewExpenseData();
    float showIncomes(long int dateForSorting);
    float showExpenses(long int dateForSorting);
    float showIncomesForPreviousMonth(long int upperBoundDateForSorting, long int lowerBoundDateForSorting);
    float showExpensesForPreviousMonth(long int upperBoundDateForSorting, long int lowerBoundDateForSorting);

public:
    FinancesManager(string incomesFileName, string expensesFileName, int loggedInUserId)
    : incomesFile(incomesFileName), expensesFile(expensesFileName), LOGGED_IN_USER_ID(loggedInUserId)
    {
        incomes = incomesFile.getIncomesOfLoggedUserFromFile(LOGGED_IN_USER_ID);
        expenses = expensesFile.getExpensesOfLoggedUserFromFile(LOGGED_IN_USER_ID);
    };

    void addIncome();
    void addExpense();
    void showAllIncomes();
    void showAllExpenses();
    void showBalanceForCurrentMonth();
    void showBalanceForPreviousMonth();
    void showBalanceForSelectedPeriod();

};

#endif
