#include "Income.h"

void Income::setIncomeId(int id)
{
    incomeId = id;
}
void Income::setUserId(int idUser)
{
    userId = idUser;
}
void Income::setDate(string datee)
{
    date = datee;
}
void Income::setItemName(string itemName)
{
    item = itemName;
}
void Income::setAmount(float itemAmoutn)
{
    amount = itemAmoutn;
}

int Income::getIncomeId()
{
    return incomeId;
}
int Income::getUserId()
{
    return userId;
}
string Income::getDate()
{
    return date;
}
string Income::getItemName()
{
    return item;
}
float Income::getAmount()
{
    return amount;
}
