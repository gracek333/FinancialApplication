#include "FinancesManager.h"
#include "CommonUsedMethods.h"
#include "DateManager.h"

void FinancesManager :: addIncome()
{
    Income income;
    income = inputNewIncomeData();

    incomes.push_back(income);

   /* if (incomesFile.addIncomeToFile(income))
    {
        cout << "Nowy adresat zostal dodany. " << endl;
    }
    else
    {
        cout << "Blad. Nie udalo sie dodac nowego adresata. " << endl;
    }*/
    showAllIncomes();
    system ("pause");
}

Income FinancesManager :: inputNewIncomeData()
{
    char choice;
    Income income;
    int incomeId, userId;
    long int date;
    float amount;
    string item;

    income.setIncomeId(1); // wstepnie
    income.setUserId(LOGGED_IN_USER_ID);

    system ("cls");
    cout << " >>> DODAWANIE NOWEGO ADRESATA <<<" << endl << endl;

    while (true)
    {
        cout << "Czy przychod dotyczy dnia dzisiejszego? (t / n):  ";
        choice = CommonUsedMethods :: getChar();

        if(choice == 't' || choice == 'T')
        {
            date = DateManager :: convertDateToIntForVector(DateManager :: getDateFromSystem());
            break;
        }
        else if (choice == 'n' || choice == 'N')
        {
            date = DateManager :: convertDateToIntForVector(DateManager :: getDateFromUser());
            break;
        }
        else
        {
            cout << "Wpisales bledny znak. Sprobuj ponownie." << endl;
        }
    }
    cout << "Podaj kategorie przychodu: ";
    item = CommonUsedMethods :: getPhrase();

    cout << "Podaj kwote: ";
    amount = CommonUsedMethods :: getFloatFromUser();

    income.setDate(date);
    income.setItem(item);
    income.setAmount(amount);

    return income;
}

void FinancesManager :: showAllIncomes()
{
    system("cls");
    if (!incomes.empty())
    {
        cout << "             >>> PRZYCHODY <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        for (vector <Income> :: iterator itr = incomes.begin(); itr != incomes.end(); itr++)
        {
            cout << endl << "Id przychodu:                 " <<(*itr).getIncomeId() << endl;
            cout << "User id:               " << (*itr).getUserId() << endl;
            cout << "Data:           " << (*itr).getDate() << endl;
            cout << "Kategoria:     " << (*itr).getItem() << endl;
            cout << "Kwota:              " << (*itr).getAmount() << endl;
        }
        cout << endl;
    }
    else
    {
        cout << endl << "Ksiazka adresowa jest pusta." << endl << endl;
    }
    system("pause");
}
