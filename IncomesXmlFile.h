#ifndef INCOMESXMLFILE_H
#define INCOMESXMLFILE_H
#include <iostream>

using namespace std;

class IncomesXmlFile{
    const string INCOMES_FILE_NAME;
public:
      IncomesXmlFile(string incomesFileName) : INCOMES_FILE_NAME(incomesFileName){};
};
#endif
