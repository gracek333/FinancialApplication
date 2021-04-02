#ifndef EXPENSESFILE_H
#define EXPENSESFILE_H

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

class ExpensesFile
{
    const string EXPENSES_FILE_NAME;

public:
    ExpensesFile(string expensesFileName) : EXPENSES_FILE_NAME(expensesFileName) {};
    string getExpensesFileName();

};

#endif
