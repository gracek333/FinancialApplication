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

public:
    FinancesManager(string incomesFileName, string expensesFileName, int loggedInUserId)
    : incomesFile(incomesFileName), expensesFile(expensesFileName), LOGGED_IN_USER_ID(loggedInUserId)
    {
        incomes = incomesFile.getIncomesFromFile();
        //adresaci = plikZAdresatami.wczytajAdresatowZalogowanegoUzytkownikaZPliku(LOGGED_IN_USER_ID);
    };

    void addIncome();
    void showAllIncomes();

    /*void wyszukajAdresatowPoImieniu();
    void wyszukajAdresatowPoNazwisku();
    void usunAdresata();
    void edytujAdresata();
    void wyswietlWszystkichAdresatow();*/

};

#endif
