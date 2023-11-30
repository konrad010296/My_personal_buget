#ifndef EXPENSE_H
#define EXPENSE_H
#include <iostream>

using namespace std;

class Expense
{
    int expenseId;
    int userId;
    string date;
    string item;
    float amount;

public:
void setExpenseId(int id);
void setUserId(int idUser);
void setDate(string datee);
void setItemName(string itemName);
void setAmount(float itemAmoutn);

int getExpenseId();
int getUserId();
string getDate();
string getItemName();
float getAmount();
};
#endif
