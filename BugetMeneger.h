#ifndef USERMAININTERFACE_H
#define USERMAININTERFACE_H
#include <iostream>
#include "IncomesXmlFile.h"
#include "ExpensesXmlFile.h"
#include "Income.h"
#include "Expense.h"
#include "HelperMethod.h"
#include "conio.h"
#include <windows.h>

using namespace std;

class BugetMeneger{

IncomesXmlFile incomeXmlFile;
ExpensesXmlFile expenseXmlFile;
int idLoggedUser;


public:
    BugetMeneger(string incomesFileName,string expensesFileName, int loggedUser) : incomeXmlFile(incomesFileName), expenseXmlFile(expensesFileName), idLoggedUser(loggedUser){};
void addAnExpense();
void balanceSheetForTheCurrentMonth();
void balanceFromThePreviousMonth();
void balanceSheetForTheSelectedPeriod();
void changePassword();
void logOut();


};
#endif
