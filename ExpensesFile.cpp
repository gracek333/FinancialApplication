#include "ExpensesFile.h"
#include "CommonUsedMethods.h"
#include "Markup.h"
#include "DateManager.h"

string ExpensesFile :: getExpensesFileName()
{
    return EXPENSES_FILE_NAME;
}

void ExpensesFile :: addExpenseToFile(Expense expense)
{
    CMarkup xml;
    bool fileExists = xml.Load( EXPENSES_FILE_NAME );

    if (!fileExists)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Expenses");
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("Expense");
    xml.IntoElem();
    xml.AddElem("ExpenseId", expense.getExpenseId());
    xml.AddElem("UserId", expense.getUserId());
    xml.AddElem("Date", DateManager :: convertDateInIntToString(expense.getDate()));
    xml.AddElem("Item", expense.getItem());
    xml.AddElem("Amount", CommonUsedMethods :: convertFloatToString(expense.getAmount()));

    setLastExpenseId(expense.getExpenseId());

    xml.Save(EXPENSES_FILE_NAME);
}

vector <Expense> ExpensesFile :: getExpensesOfLoggedUserFromFile(int loggedInUserId)
{
    Expense expense;
    vector <Expense> expenses;
    CMarkup xml;
    bool fileExists = xml.Load( EXPENSES_FILE_NAME );
    if (fileExists)
    {
        xml.ResetPos();
        xml.FindElem();
        xml.IntoElem();
        while (xml.FindElem("Expense"))
        {
            xml.FindChildElem("ExpenseId");
            expense.setExpenseId(atoi(xml.GetChildData().c_str()));
            xml.FindChildElem("UserId");
            expense.setUserId(atoi(xml.GetChildData().c_str()));
            xml.FindChildElem("Date");
            expense.setDate(DateManager::convertDateToIntForVector(DateManager::convertDateFromUserToStructure(xml.GetChildData())));
            xml.FindChildElem("Item");
            expense.setItem(xml.GetChildData());
            xml.FindChildElem("Amount");
            expense.setAmount(CommonUsedMethods::convertStringToFloat(xml.GetChildData()));
            if (expense.getUserId() == loggedInUserId)
            {
                expenses.push_back(expense);
            }
            setLastExpenseId(expense.getExpenseId());
        }
        xml.Save(EXPENSES_FILE_NAME);
    }

    return expenses;
}

void ExpensesFile :: setLastExpenseId(int newLastExpenseId)
{
    lastExpenseId = newLastExpenseId;
}

int ExpensesFile :: getLastExpenseId()
{
    return lastExpenseId;
}
