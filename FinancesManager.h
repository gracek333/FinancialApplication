#ifndef FINANCESMANAGER_H
#define FINANCESMANAGER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <sstream>

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

public:
    FinancesManager(string incomesFileName, string expensesFileName, int loggedInUserId)
    : incomesFile(incomesFileName), expensesFile(expensesFileName), LOGGED_IN_USER_ID(loggedInUserId)
    {
        incomes = incomesFile.getIncomesFromFile();
        expenses = expensesFile.getExpensesFromFile();
    };

    void addIncome();
    void addExpense();
    void showAllIncomes();
    void showAllExpenses();

};

#endif
