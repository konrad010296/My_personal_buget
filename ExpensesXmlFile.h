#ifndef EXPENSEXMLFILE_H
#define EXPENSEXMLFILE_H
#include <iostream>
#include <vector>
#include "Expense.h"
#include "HelperMethod.h"
#include "DateMeneger.h"
#include "XmlFile.h"
#include "Markup.h"

using namespace std;

class ExpensesXmlFile : public XmlFile
{

    int lastExpenseId;

public:
    ExpensesXmlFile(string expensesFilename) : XmlFile(expensesFilename)
    {
        lastExpenseId = 0;
    };
    void addExpenseToFile(Expense expense);
    vector <Expense> readExpensesFromFile(int idLoggedUser);
    int getLastExpenseId();

};
#endif
