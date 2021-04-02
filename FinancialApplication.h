#ifndef FINANCIALAPPLICATION_H
#define FINANCIALAPPLICATION_H

#include <iostream>

#include "UserManager.h"

using namespace std;

class FinancialApplication
{
    UserManager userManager;

public:
    FinancialApplication(string usersFileName) : userManager(usersFileName)
    {
    };

    void registerNewUser();
    void printAllUsers();
    void logInUser();
    void changeLoggedInUserPassword();
    void logOutUser();
    char chooseOptionInMainMenu();
    char chooseOptionInUserMenu();
    bool isUserLoggedIn();

};

#endif
