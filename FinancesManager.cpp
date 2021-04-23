#include "FinancesManager.h"
#include "CommonUsedMethods.h"
#include "DateManager.h"
#include <math.h>

void FinancesManager :: addIncome()
{
    Income income;
    income = inputNewIncomeData();

    incomes.push_back(income);

    incomesFile.addIncomeToFile(income);

    cout << "Nowy przychod zostal dodany. " << endl << endl;

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
    Income income;
    float amount;
    string item;

    system ("cls");
    cout << " >>> DODAWANIE NOWEGO PRZYCHODU <<<" << endl << endl;

    income.setIncomeId(incomesFile.getLastIncomeId()+1);
    income.setUserId(LOGGED_IN_USER_ID);

    income.setDate(DateManager::askUserForDateChoosing());

    cout << "Podaj kategorie przychodu: ";
    item = CommonUsedMethods :: getPhrase();

    cout << "Podaj kwote: ";
    amount = CommonUsedMethods :: getFloatFromUser();

    income.setItem(item);
    income.setAmount(amount);

    return income;
}

void FinancesManager :: showAllIncomes()
{
    system("cls");

    if (!incomes.empty())
    {
        cout << "                    >>> PRZYCHODY <<<" << endl;
        cout << "--------------------------------------------------------------" << endl;

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

    cout << "Nowy przychod zostal dodany. " << endl << endl;

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
    Expense expense;
    float amount;
    string item;

    system ("cls");
    cout << " >>> DODAWANIE NOWEGO WYDATKU <<<" << endl << endl;

    expense.setExpenseId(expensesFile.getLastExpenseId() + 1);
    expense.setUserId(LOGGED_IN_USER_ID);
    expense.setDate(DateManager::askUserForDateChoosing());

    cout << "Podaj kategorie wydatku: ";
    item = CommonUsedMethods :: getPhrase();

    cout << "Podaj kwote: ";
    amount = CommonUsedMethods :: getFloatFromUser();

    expense.setItem(item);
    expense.setAmount(amount);

    return expense;
}

void FinancesManager :: showAllExpenses()
{
    system("cls");

    if (!expenses.empty())
    {
        cout << "                    >>> WYDATKI <<<" << endl;
        cout << "--------------------------------------------------------------" << endl;

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
    sort (incomes.begin(), incomes.end(), Income::sortVectorByDatesFromTheOldest);
    sort (expenses.begin(), expenses.end(), Expense::sortVectorByDatesFromTheOldest);

    long int dateForSorting = 0;
    float sumOfIncomes = 0.0;
    float sumOfExpenses = 0.0;
    float balance = 0.0;

    dateForSorting = ((DateManager::convertDateToIntForVector( DateManager::getDateFromSystem())) / 100) * 100;

    sumOfIncomes = showIncomes(dateForSorting);
    sumOfExpenses = showExpenses(dateForSorting);
    balance = sumOfIncomes - sumOfExpenses;
    cout << "Suma przychodow: " << sumOfIncomes << endl;
    cout << "Suma wydatkow: " << sumOfExpenses << endl;
    cout << "Bilans: " << (round(balance*100))/100 << endl;

    system("pause");
}

float FinancesManager :: showIncomes(long int dateForSorting)
{
    system("cls");
    float sum = 0.0;

    if (!incomes.empty())
    {
        cout << "                    >>> PRZYCHODY <<<" << endl;
        cout << "--------------------------------------------------------------" << endl;
        cout << "Data                 Kategoria                 Kwota w zlotych" << endl;

        for (vector <Income> :: iterator itr = incomes.begin(); itr != incomes.end(); itr++)
        {
            if ((*itr).getDate() > dateForSorting)
            {
                cout << DateManager::convertDateInIntToString((*itr).getDate()) << "           " << (*itr).getItem() << "                       " <<  (*itr).getAmount() << endl;
                sum = sum + (*itr).getAmount();
            }
        }
        cout << endl;
    }
    else
    {
        cout << endl << "Brak przychodow spelniajacych podane kryterium. " << endl << endl;
    }

    return sum;
}

float FinancesManager :: showExpenses(long int dateForSorting)
{
    float sum = 0.0;

    if (!expenses.empty())
    {
        cout << "                    >>> WYDATKI <<<" << endl;
        cout << "--------------------------------------------------------------" << endl;
        cout << "Data                 Kategoria                 Kwota w zlotych" << endl;

        for (vector <Expense> :: iterator itr = expenses.begin(); itr != expenses.end(); itr++)
        {
            if ((*itr).getDate() > dateForSorting)
            {
                cout << DateManager::convertDateInIntToString((*itr).getDate()) << "           " << (*itr).getItem() << "                       " <<  (*itr).getAmount() << endl;
                sum = sum + (*itr).getAmount();
            }
        }
        cout << endl;
    }
    else
    {
        cout << endl << "Brak wydatkow spelniajacych podane kryterium. " << endl << endl;
    }

    return sum;
}

void FinancesManager :: showBalanceForPreviousMonth()
{
    sort (incomes.begin(), incomes.end(), Income::sortVectorByDatesFromTheOldest);
    sort (expenses.begin(), expenses.end(), Expense::sortVectorByDatesFromTheOldest);

    Date date;
    long int upperBoundDateForSorting = 0;
    long int lowerBoundDateForSorting = 0;
    float sumOfIncomes = 0.0;
    float sumOfExpenses = 0.0;
    float balance = 0.0;

    date = DateManager :: getFinalDateOfPreviousMonth();

    upperBoundDateForSorting = ((DateManager::convertDateToIntForVector(date)));
    lowerBoundDateForSorting = (((DateManager::convertDateToIntForVector(date)) / 100) * 100) + 1;

    sumOfIncomes = showIncomesForPreviousMonth(upperBoundDateForSorting, lowerBoundDateForSorting);
    sumOfExpenses = showExpensesForPreviousMonth(upperBoundDateForSorting, lowerBoundDateForSorting);

    cout << "Suma przychodow: " << sumOfIncomes << endl;
    cout << "Suma wydatkow: " << sumOfExpenses << endl;
    balance = sumOfIncomes - sumOfExpenses;
    cout << "Bilans: " << (round(balance*100))/100 << endl;

    system("pause");
}

float  FinancesManager :: showIncomesForPreviousMonth(long int upperBoundDateForSorting, long int lowerBoundDateForSorting)
{
    system("cls");
    float sum = 0.0;

    if (!incomes.empty())
    {
        cout << "                    >>> PRZYCHODY <<<" << endl;
        cout << "--------------------------------------------------------------" << endl;
        cout << "Data                 Kategoria                 Kwota w zlotych" << endl;

        for (vector <Income> :: iterator itr = incomes.begin(); itr != incomes.end(); itr++)
        {
            if (((*itr).getDate() >= lowerBoundDateForSorting) && ((*itr).getDate() <= upperBoundDateForSorting) )
            {
                cout << DateManager::convertDateInIntToString((*itr).getDate()) << "           " << (*itr).getItem() << "                       " <<  (*itr).getAmount() << endl;
                sum = sum + (*itr).getAmount();
            }
        }
        cout << endl;
    }
    else
    {
        cout << endl << "Brak przychodow spelniajacych podane kryterium. " << endl << endl;
    }

    return sum;
}

float  FinancesManager :: showExpensesForPreviousMonth(long int upperBoundDateForSorting, long int lowerBoundDateForSorting)
{
    float sum = 0.0;

    if (!expenses.empty())
    {
        cout << "                    >>> WYDATKI <<<" << endl;
        cout << "--------------------------------------------------------------" << endl;
        cout << "Data                 Kategoria                 Kwota w zlotych" << endl;

        for (vector <Expense> :: iterator itr = expenses.begin(); itr != expenses.end(); itr++)
        {
            if (((*itr).getDate() >= lowerBoundDateForSorting) && ((*itr).getDate() <= upperBoundDateForSorting) )
            {
                cout << DateManager::convertDateInIntToString((*itr).getDate()) << "           " << (*itr).getItem() << "                       " <<  (*itr).getAmount() << endl;
                sum = sum + (*itr).getAmount();
            }
        }
        cout << endl;
    }
    else
    {
        cout << endl << "Brak wydatkow spelniajacych podane kryterium. " << endl << endl;
    }

    return sum;
}

void FinancesManager :: showBalanceForSelectedPeriod()
{
    sort (incomes.begin(), incomes.end(), Income::sortVectorByDatesFromTheOldest);
    sort (expenses.begin(), expenses.end(), Expense::sortVectorByDatesFromTheOldest);

    float sumOfIncomes = 0.0;
    float sumOfExpenses = 0.0;
    float balance = 0.0;
    long int firstDate, secondDate;

    cout << "Podaj date od ktorej ma zostac wyswietlony bilans." << endl;
    firstDate = DateManager::convertDateToIntForVector(DateManager::getDateFromUser());
    cout << endl << "Podaj date do ktorej ma zostac wyswietlony bilans." << endl;
    secondDate = DateManager::convertDateToIntForVector(DateManager::getDateFromUser());

    if (firstDate > secondDate)
    {
        sumOfIncomes = showIncomesForPreviousMonth(firstDate, secondDate);
        sumOfExpenses = showExpensesForPreviousMonth(firstDate, secondDate);
    }
    else
    {
        sumOfIncomes = showIncomesForPreviousMonth(secondDate, firstDate);
        sumOfExpenses = showExpensesForPreviousMonth(secondDate, firstDate);
    }

    cout << "Suma przychodow: " << sumOfIncomes << endl;
    cout << "Suma wydatkow: " << sumOfExpenses << endl;
    balance = sumOfIncomes - sumOfExpenses;
    cout << "Bilans: " << (round(balance*100))/100 << endl;

    system("pause");
}
