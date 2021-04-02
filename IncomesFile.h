#ifndef INCOMESFILE_H
#define INCOMESFILE_H

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

class IncomesFile
{
    const string INCOMES_FILE_NAME;

public:
    IncomesFile(string incomesFileName) : INCOMES_FILE_NAME(incomesFileName) {};
    string getIncomesFileName();

};

#endif
