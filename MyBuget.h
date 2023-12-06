#ifndef MYBUGET_H
#define MYBUGET_H
#include <iostream>
#include "UserMeneger.h"
#include "User.h"
#include "UserXmlFile.h"
#include "BugetMeneger.h"
#include <conio.h>

using namespace std;

class MyBuget
{

    UserMeneger userMeneger;
    BugetMeneger *bugetMeneger;
    const string INCOMES_FILE_NAME;
    const string EXPENSES_FILE_NAME;



public:
    MyBuget(string usersFileName, string incomesFileName, string expensesFileName) : userMeneger(usersFileName), INCOMES_FILE_NAME(incomesFileName), EXPENSES_FILE_NAME(expensesFileName)
    {
        bugetMeneger = NULL;
    };
    ~MyBuget()
    {
        delete bugetMeneger;
        bugetMeneger = NULL;
    }
    char logInPanel();
    void registerUser();
    char userPanel();
    void logIn();
    int getLoggedUserId();
    void addIncome();
    void addAnExpense();
    void balanceSheetForTheCurrentMonth();
    void balanceFromThePreviousMonth();



};
#endif
