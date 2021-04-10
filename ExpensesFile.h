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

public:
    ExpensesFile(string expensesFileName) : EXPENSES_FILE_NAME(expensesFileName) {};
    string getExpensesFileName();
    vector <Expense> getExpensesFromFile();
    void addExpenseToFile(Expense expense);
};

#endif
