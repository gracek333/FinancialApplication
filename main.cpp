#include <iostream>
#include "FinancialApplication.h"

using namespace std;

int main()
{
    FinancialApplication financialApplication("users.xml");

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
            financialApplication.printAllUsers();
            system("pause");
            break;

        }
    }

    return 0;
}
