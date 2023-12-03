#include "BugetMeneger.h"

void BugetMeneger::addIncome()
{
    string date = "";
    system("CLS");
    Income income;
    bool goodDate = false;

    if(incomes.size() == 0)
        income.setIncomeId(1);
    else
    income.setIncomeId(incomes[incomes.size() - 1].getIncomeId() + 1);
    income.setUserId(idLoggedUser);
    if(HelperMethod::askAboutDate()){
    income.setDate(HelperMethod::getCurrentDate());
    }else{
        while(!goodDate){
    cout << "Set date in format rrrr-mm-dd : " << endl;
    income.setDate(HelperMethod::getLine());
    goodDate = HelperMethod::checkDateFormat(income.getDate());
        }
    }
    cout << "Nazwa itemu : " << endl;
    income.setItemName(HelperMethod::getLine());
    cout << "Iloœæ : " << endl;
    income.setAmount(HelperMethod::convertionStringToInt(HelperMethod::getLine()));

    incomes.push_back(income);
    incomeXmlFile.addIncomeToFile(income);
}


