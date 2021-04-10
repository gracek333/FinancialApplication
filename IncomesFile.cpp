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

    xml.Save(INCOMES_FILE_NAME);
}
