#ifndef EXPENSEXMLFILE_H
#define EXPENSEXMLFILE_H
#include <iostream>
#include <vector>
#include "Expense.h"
#include "HelperMethod.h"
#include "Markup.h"

using namespace std;

class ExpensesXmlFile{
    const string EXPENSES_FILE_NAME;
    int lastExpenseId;

public:
    ExpensesXmlFile(string expensesFilename) : EXPENSES_FILE_NAME(expensesFilename){
    lastExpenseId = 0;
    };
    void addExpenseToFile(Expense expense, string date);
    vector <Expense> readExpensesFromFile(int idLoggedUser);

};
#endif
