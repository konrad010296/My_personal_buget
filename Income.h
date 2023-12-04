#ifndef INCOME_H
#define INCOME_H
#include <iostream>

using namespace std;

class Income{
    int incomeId;
    int userId;
    int date;
    string item;
    float amount;

public:
void setIncomeId(int id);
void setUserId(int idUser);
void setDate(int datee);
void setItemName(string itemName);
void setAmount(float itemAmoutn);

int getIncomeId();
int getUserId();
int getDate();
string getItemName();
float getAmount();
};
#endif
