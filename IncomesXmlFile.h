#ifndef INCOMESXMLFILE_H
#define INCOMESXMLFILE_H
#include "Income.h"
#include <iostream>
#include <vector>
#include "Markup.h"
#include "HelperMethod.h"

using namespace std;

class IncomesXmlFile
{
    const string INCOMES_FILE_NAME;
    int lastIncomeId;

public:
    IncomesXmlFile(string incomesFileName) : INCOMES_FILE_NAME(incomesFileName)
    {
        lastIncomeId = 0;
    };
    vector <Income> loadIncomesFromXmlFile(int idLoggedUser);
    void addIncomeToFile(Income incomes, string date, string amount);
};
#endif
