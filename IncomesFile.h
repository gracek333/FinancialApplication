#ifndef INCOMESFILE_H
#define INCOMESFILE_H

#include <iostream>
#include <vector>
#include <fstream>

#include "Income.h"

using namespace std;

class IncomesFile
{
    const string INCOMES_FILE_NAME;

public:
    IncomesFile(string incomesFileName) : INCOMES_FILE_NAME(incomesFileName) {};
    string getIncomesFileName();
    vector <Income> getIncomesFromFile();
    void addIncomeToFile(Income income);
};

#endif
