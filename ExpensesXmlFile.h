#ifndef EXPENSEXMLFILE_H
#define EXPENSEXMLFILE_H
#include <iostream>

using namespace std;

class ExpensesXmlFile{
    const string EXPENSES_FILE_NAME;

public:
    ExpensesXmlFile(string expensesFilename) : EXPENSES_FILE_NAME(expensesFilename){};
 //   void addExpenseToFile(idOfLoggedUser);
    void readExpensesFromFile();

};
#endif
