#ifndef FINANCIALAPPLICATION_H
#define FINANCIALAPPLICATION_H

#include <iostream>

#include "UserManager.h"

using namespace std;

class FinancialApplication
{
    UserManager userManager;

public:

    void registerNewUser();
    void printAllUsers();

};

#endif
