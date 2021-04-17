#ifndef FINANCIALAPPLICATION_H
#define FINANCIALAPPLICATION_H

#include <iostream>

#include "UserManager.h"
#include "FinancesManager.h"

using namespace std;

class FinancialApplication
{
    UserManager userManager;
    FinancesManager *financesManager;
    const string INCOMES_FILE_NAME;
    const string EXPENSES_FILE_NAME;

public:
    FinancialApplication(string usersFileName, string incomesFileName, string expensesFileName)
        : userManager(usersFileName), INCOMES_FILE_NAME(incomesFileName), EXPENSES_FILE_NAME(expensesFileName)
    {
        financesManager = NULL;
    };

    ~FinancialApplication()
    {
        delete financesManager;
        financesManager = NULL;
    }
    void registerNewUser();
    void printAllUsers();
    void logInUser();
    void changeLoggedInUserPassword();
    void logOutUser();
    char chooseOptionInMainMenu();
    char chooseOptionInUserMenu();
    bool isUserLoggedIn();
    void addIncome();
    void addExpense();
    void showBalanceForCurrentMonth();
    void showBalanceForPreviousMonth();

};

#endif
