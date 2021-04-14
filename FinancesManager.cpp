#include "FinancesManager.h"
#include "CommonUsedMethods.h"
#include "DateManager.h"



void FinancesManager :: addIncome()
{
    Income income;
    income = inputNewIncomeData();

    incomes.push_back(income);

    incomesFile.addIncomeToFile(income);

    cout << "Nowy przychod zostal dodany. " << endl;


    showAllIncomes();
    system ("pause");
}

int FinancesManager :: getIdForNewIncome()
{
    if (incomes.empty() == true)
        return 1;
    else
        return incomes.back().getIncomeId() + 1;
}

Income FinancesManager :: inputNewIncomeData()
{
    char choice;
    Income income;
    long int date;
    float amount;
    string item;

    income.setIncomeId(incomesFile.getLastIncomeId()+1);
    income.setUserId(LOGGED_IN_USER_ID);

    system ("cls");
    cout << " >>> DODAWANIE NOWEGO PRZYCHODU <<<" << endl << endl;

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
        cout << endl << "Plik z przychodami jest pusty." << endl << endl;
    }
    system("pause");
}

void FinancesManager :: addExpense()
{
    Expense expense;
    expense = inputNewExpenseData();

    expenses.push_back(expense);

    expensesFile.addExpenseToFile(expense);

    cout << "Nowy przychod zostal dodany. " << endl;


    showAllExpenses();
    system ("pause");
}

int FinancesManager :: getIdForNewExpense()
{
    if (expenses.empty() == true)
        return 1;
    else
        return expenses.back().getExpenseId() + 1;
}

Expense FinancesManager :: inputNewExpenseData()
{
    char choice;
    Expense expense;
    long int date;
    float amount;
    string item;

    expense.setExpenseId(expensesFile.getLastExpenseId() + 1);
    expense.setUserId(LOGGED_IN_USER_ID);

    system ("cls");
    cout << " >>> DODAWANIE NOWEGO WYDATKU <<<" << endl << endl;

    while (true)
    {
        cout << "Czy wydatek dotyczy dnia dzisiejszego? (t / n):  ";
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
    cout << "Podaj kategorie wydatku: ";
    item = CommonUsedMethods :: getPhrase();

    cout << "Podaj kwote: ";
    amount = CommonUsedMethods :: getFloatFromUser();

    expense.setDate(date);
    expense.setItem(item);
    expense.setAmount(amount);

    return expense;
}

void FinancesManager :: showAllExpenses()
{
    system("cls");
    if (!expenses.empty())
    {
        cout << "             >>> WYDATKI <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        for (vector <Expense> :: iterator itr = expenses.begin(); itr != expenses.end(); itr++)
        {
            cout << endl << "Id wydatku:                 " <<(*itr).getExpenseId() << endl;
            cout << "User id:               " << (*itr).getUserId() << endl;
            cout << "Data:           " << (*itr).getDate() << endl;
            cout << "Kategoria:     " << (*itr).getItem() << endl;
            cout << "Kwota:              " << (*itr).getAmount() << endl;
        }
        cout << endl;
    }
    else
    {
        cout << endl << "Plik z wydatkami jest pusty." << endl << endl;
    }
    system("pause");
}


void FinancesManager :: showBalanceForCurrentMonth()
{
    sort (incomes.begin(), incomes.end(), Income::Less);

    long int dateForSorting = 0;
    float sumOfIncomes = 0.0;
    float sumOfExpenses = 0.0;
    float balance = 0.0;

    dateForSorting = ((DateManager::convertDateToIntForVector( DateManager::getDateFromSystem())) / 100) * 100;
    cout << "Data do sortowania: " << dateForSorting << endl;

    sumOfIncomes = showIncomes(dateForSorting);

    system("pause");

}

float FinancesManager :: showIncomes(long int dateForSorting)
{
    float sum = 0.0;

    if (!incomes.empty())
    {
        cout << "             >>> PRZYCHODY <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        for (vector <Income> :: iterator itr = incomes.begin(); itr != incomes.end(); itr++)
        {
            if ((*itr).getDate() > dateForSorting)
            {
                cout << endl << "Id przychodu:                 " <<(*itr).getIncomeId() << endl;
                cout << "User id:               " << (*itr).getUserId() << endl;
                cout << "Data:           " << (*itr).getDate() << endl;
                cout << "Kategoria:     " << (*itr).getItem() << endl;
                cout << "Kwota:              " << (*itr).getAmount() << endl;
                sum = sum + (*itr).getAmount();
            }
        }
        cout << endl;
    }
    else
    {
        cout << endl << "Brak przychodow spelniajacych podane kryterium. " << endl << endl;
    }
    cout << " Suma przychodow: " << sum << endl;
    system("pause");

    return sum;
}
