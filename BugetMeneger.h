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
#include <vector>
#include <algorithm>

using namespace std;

class BugetMeneger
{

    IncomesXmlFile incomeXmlFile;
    ExpensesXmlFile expenseXmlFile;
    vector <Income> incomes;
    vector <Expense> expenses;
    const int IDLOGGEDUSER;
    void printBalance(int startDate, int endDate);


public:
    BugetMeneger(string incomesFileName,string expensesFileName, int loggedUser) : incomeXmlFile(incomesFileName), expenseXmlFile(expensesFileName), IDLOGGEDUSER(loggedUser)
    {
        incomes = incomeXmlFile.loadIncomesFromXmlFile(IDLOGGEDUSER);
        expenses = expenseXmlFile.readExpensesFromFile(IDLOGGEDUSER);
    };
    void addIncome();
    void addAnExpense();
    void balanceSheetForTheCurrentMonth();
    void balanceFromThePreviousMonth();
    void balanceSheetForTheSelectedPeriod();
    void changePassword();
    void logOut();



};
#endif
