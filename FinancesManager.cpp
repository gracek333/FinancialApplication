#include "FinancesManager.h"
#include "CommonUsedMethods.h"

void FinancesManager :: addIncome()
{
    Income income;

    system("cls");
    cout << " >>> DODAWANIE NOWEGO PRZYCHODU <<<" << endl << endl;
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
    Income income;
    int incomeId, userId;
    string date, item, amount;

    income.setIncomeId(1);
    income.setUserId(LOGGED_IN_USER_ID);

    cout << "Podaj date: ";
    date = CommonUsedMethods :: getPhrase();

    cout << "Podaj kategorie: ";
    item = CommonUsedMethods :: getPhrase();

    cout << "Podaj kwote: ";
    amount = CommonUsedMethods :: getPhrase();

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
