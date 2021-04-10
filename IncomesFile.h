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
    int lastIncomeId;

    void setLastIncomeId(int newLasIncomeId);

public:
    IncomesFile(string incomesFileName) : INCOMES_FILE_NAME(incomesFileName) {lastIncomeId = 0;};
    string getIncomesFileName();
    vector <Income> getIncomesOfLoggedUserFromFile(int loggedInUserId);
    void addIncomeToFile(Income income);
    int getLastIncomeId();
};

#endif
