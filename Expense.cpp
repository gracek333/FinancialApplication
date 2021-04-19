#include "Expense.h"

void Expense :: setExpenseId(int newId)
{
    if (newId >= 0)
        expenseId = newId;
}
void Expense :: setUserId(int newUserId)
{
    if (newUserId >= 0)
        userId = newUserId;
}
void Expense :: setDate(long int newDate)
{
    date = newDate;
}
void Expense :: setItem(string newItem)
{
    item = newItem;
}
void Expense :: setAmount(float newAmount)
{
    amount = newAmount;
}

int Expense :: getExpenseId()
{
    return expenseId;
}
int Expense :: getUserId()
{
    return userId;
}
long int Expense :: getDate()
{
    return date;
}
string Expense :: getItem()
{
    return item;
}
float Expense :: getAmount()
{
    return amount;
}
bool Expense :: sortVectorByDatesFromTheOldest (const Expense& x, const Expense& y)
{
    return x.date < y.date;
}
