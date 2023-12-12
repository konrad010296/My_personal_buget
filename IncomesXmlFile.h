#ifndef INCOMESXMLFILE_H
#define INCOMESXMLFILE_H
#include "Income.h"
#include <iostream>
#include <vector>
#include "Markup.h"
#include "HelperMethod.h"
#include "XmlFile.h"
#include "DateMeneger.h"

using namespace std;

class IncomesXmlFile : private XmlFile
{
    int lastIncomeId;

public:
    IncomesXmlFile(string incomesFileName) : XmlFile(incomesFileName)
    {
        lastIncomeId = 0;
    };
    vector <Income> loadIncomesFromXmlFile(int idLoggedUser);
    void addIncomeToFile(Income incomes);
    int getLastIncomeId();
};
#endif
