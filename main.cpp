#include <iostream>
#include "FinancialApplication.h"

using namespace std;

int main()
{
    FinancialApplication financialApplication;
    financialApplication.registerNewUser();
    financialApplication.registerNewUser();
    financialApplication.printAllUsers();
    return 0;
}
