#include <iostream>
#include "FinancialApplication.h"

using namespace std;

int main()
{
    FinancialApplication financialApplication("users.xml","incomes.xml","expenses.xml");

    char choice;

    while (true)
    {
        if(!financialApplication.isUserLoggedIn())
        {
            choice = financialApplication.chooseOptionInMainMenu();

            switch(choice)
            {
            case '1':
                financialApplication.registerNewUser();
                break;
            case '2':
                financialApplication.logInUser();
                break;
            case '9':
                exit(0);
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                system("pause");
                break;
            }
        }
        else
        {
            choice = financialApplication.chooseOptionInUserMenu();

            switch (choice)
            {
            case '1':
                financialApplication.addIncome();
                break;
            case '2':
                //financialApplication.addExpense();
                break;
            case '3':
                //financialApplication.showBalanceForCurrentMonth();
                break;
            case '4':
                //financialApplication.showBalanceForPreviosMonth();
                break;
            case '5':
                //financialApplication.showBalanceForSelectedPeriod();
                break;
            case '6':
                financialApplication.changeLoggedInUserPassword();
                break;
            case '7':
                financialApplication.logOutUser();
                break;

            }
        }
    }
    return 0;
}
