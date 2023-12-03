#include "BugetMeneger.h"

void BugetMeneger::addIncome()
{
    system("CLS");
    Income income;

    cout << "Ustaw Id Zamowienia : " << endl;
    income.setIncomeId(HelperMethod::convertionStringToInt(HelperMethod::getLine()));
    cout << "Ustaw Id Zalgoowanego : " << endl;
    income.setUserId(idLoggedUser);
    cout << "Ustaw Date : " << endl;
    income.setDate(HelperMethod::getLine());
    cout << "Nazwa itemu : " << endl;
    income.setItemName(HelperMethod::getLine());
    cout << "Iloœæ : " << endl;
    income.setAmount(HelperMethod::convertionStringToInt(HelperMethod::getLine()));

    incomes.push_back(income);
    incomeXmlFile.addIncomeToFile(income);
}


