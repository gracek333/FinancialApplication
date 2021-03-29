#include <iostream>
#include "FinancialApplication.h"

using namespace std;

int main()
{
    FinancialApplication financialApplication("users.xml");
    /*financialApplication.registerNewUser();
    financialApplication.registerNewUser();*/
    financialApplication.printAllUsers();
    financialApplication.registerNewUser();
    financialApplication.registerNewUser();
    financialApplication.printAllUsers();

    return 0;
}
