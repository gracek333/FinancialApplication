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

void FinancialApplication :: logInUser()
{
    userManager.logInUser();
}

bool FinancialApplication :: isUserLoggedIn()
{
    return userManager.isUserLoggedIn();
}

char FinancialApplication :: chooseOptionInMainMenu()
{
    char choice;

    system("cls");
    cout << "    >>> MENU  GLOWNE <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Rejestracja" << endl;
    cout << "2. Logowanie" << endl;
    cout << "9. Koniec programu" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    choice = CommonUsedMethods::getChar();

    return choice;
}
