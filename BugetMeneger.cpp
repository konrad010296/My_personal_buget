#include "BugetMeneger.h"

void BugetMeneger::addIncome()
{
    string date = "";
    system("CLS");
    Income income;

    if(incomes.size() == 0)
        income.setIncomeId(1);
    else
    income.setIncomeId(incomes[incomes.size() - 1].getIncomeId() + 1);
    income.setUserId(idLoggedUser);
    cout << "Set date in format rrrr-dd-mm : " << endl;
    income.setDate(HelperMethod::getCurrentDate());
    cout << "Nazwa itemu : " << endl;
    income.setItemName(HelperMethod::getLine());
    cout << "Iloœæ : " << endl;
    income.setAmount(HelperMethod::convertionStringToInt(HelperMethod::getLine()));

    incomes.push_back(income);
    incomeXmlFile.addIncomeToFile(income);
}


