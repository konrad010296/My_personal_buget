#ifndef INCOMESXMLFILE_H
#define INCOMESXMLFILE_H
#include "Income.h"
#include <iostream>
#include <vector>
#include "Markup.h"

using namespace std;

class IncomesXmlFile{
    const string INCOMES_FILE_NAME;
    int lastIncomeId;

public:
    IncomesXmlFile(string incomesFileName) : INCOMES_FILE_NAME(incomesFileName){};
    vector <Income> loadIncomesFromXmlFile(int idLoggedUser);
    void addIncomeToFile(Income incomes);
};
#endif
