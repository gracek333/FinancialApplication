#include "FinancialApplication.h"
#include "UsersFile.h"
#include "CommonUsedMethods.h"

void FinancialApplication :: registerNewUser()
{
    userManager.registerNewUser();
}
void FinancialApplication :: printAllUsers()
{
    userManager.printAllUsers();
}
