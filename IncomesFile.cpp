#include "IncomesFile.h"
#include "CommonUsedMethods.h"
#include "Markup.h"
#include "DateManager.h"

string IncomesFile :: getIncomesFileName()
{
    return INCOMES_FILE_NAME;
}

void IncomesFile :: addIncomeToFile(Income income)
{
    CMarkup xml;
    bool fileExists = xml.Load( INCOMES_FILE_NAME );

    if (!fileExists)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Incomes");
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("Income");
    xml.IntoElem();
    xml.AddElem("IncomeId", income.getIncomeId());
    xml.AddElem("UserId", income.getUserId());
    xml.AddElem("Date", DateManager :: convertDateInIntToString(income.getDate()));
    xml.AddElem("Item", income.getItem());
    xml.AddElem("Amount", CommonUsedMethods :: convertFloatToString(income.getAmount()));

    setLastIncomeId(income.getIncomeId());

    xml.Save(INCOMES_FILE_NAME);
}

vector <Income> IncomesFile :: getIncomesOfLoggedUserFromFile(int loggedInUserId)
{
    Income income;
    vector <Income> incomes;
    CMarkup xml;
    bool fileExists = xml.Load( INCOMES_FILE_NAME );
    if (fileExists)
    {
        xml.ResetPos();
        xml.FindElem();
        xml.IntoElem();
        while (xml.FindElem("Income"))
        {
            xml.FindChildElem("IncomeId");
            income.setIncomeId(atoi(xml.GetChildData().c_str()));
            xml.FindChildElem("UserId");
            income.setUserId(atoi(xml.GetChildData().c_str()));
            xml.FindChildElem("Date");
            income.setDate(DateManager::convertDateToIntForVector(DateManager::convertDateFromUserToStructure(xml.GetChildData())));
            xml.FindChildElem("Item");
            income.setItem(xml.GetChildData());
            xml.FindChildElem("Amount");
            income.setAmount(CommonUsedMethods::convertStringToFloat(xml.GetChildData()));
            if (income.getUserId() == loggedInUserId)
            {
                incomes.push_back(income);
            }
            setLastIncomeId(income.getIncomeId());
        }
        xml.Save(INCOMES_FILE_NAME);
    }

    return incomes;
}

void IncomesFile :: setLastIncomeId(int newLastIncomeId)
{
    lastIncomeId = newLastIncomeId;
}

int IncomesFile :: getLastIncomeId()
{
    return lastIncomeId;
}
