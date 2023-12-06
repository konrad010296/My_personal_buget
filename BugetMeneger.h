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
    int idLoggedUser;
    float sumOfExpenses;
    float sumOfIncomes;


public:
    BugetMeneger(string incomesFileName,string expensesFileName, int loggedUser) : incomeXmlFile(incomesFileName), expenseXmlFile(expensesFileName), idLoggedUser(loggedUser)
    {
        incomes = incomeXmlFile.loadIncomesFromXmlFile(idLoggedUser);
        expenses = expenseXmlFile.readExpensesFromFile(idLoggedUser);
        sumOfExpenses = 0;
        sumOfIncomes = 0;
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
