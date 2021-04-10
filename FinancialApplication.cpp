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
    if (userManager.isUserLoggedIn())
    {
        financesManager = new FinancesManager(INCOMES_FILE_NAME, EXPENSES_FILE_NAME, userManager.getLoggedInUserId());
    }
}

void FinancialApplication :: logOutUser()
{
    userManager.logOutUser();
    delete financesManager;
    financesManager = NULL;

}

void FinancialApplication :: changeLoggedInUserPassword()
{
    userManager.changeLoggedInUserPassword();
}

bool FinancialApplication :: isUserLoggedIn()
{
    return userManager.isUserLoggedIn();
}

void FinancialApplication :: addIncome()
{
    if (userManager.isUserLoggedIn())
    {
        financesManager -> addIncome();
    }
    else
    {
        cout << "Aby dodac wydatek, nalezy najpierw sie zalogowac" << endl;
        system("pause");
    }
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

char FinancialApplication :: chooseOptionInUserMenu()
{
    char choice;

    system("cls");
    cout << " >>> MENU UZYTKOWNIKA <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Dodaj przychod" << endl;
    cout << "2. Dodaj wydatek" << endl;
    cout << "3. Bilans z biezacego miesiaca" << endl;
    cout << "4. Bilans z poprzedniego miesiaca" << endl;
    cout << "5. Bilans z wybranego okresu" << endl;
    cout << "---------------------------" << endl;
    cout << "6. Zmien haslo" << endl;
    cout << "7. Wyloguj sie" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    choice = CommonUsedMethods :: getChar();

    return choice;

}
