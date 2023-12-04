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
    if(HelperMethod::askAboutDate())
    {
        date = HelperMethod::getCurrentDate();
        income.setDate(HelperMethod::convetionDateToInt(date));
    }
    else
    {
        while(!goodDate)
        {
            cout << "Set date in format rrrr-mm-dd : " << endl;
            date = HelperMethod::getLine();
            goodDate = HelperMethod::checkDateFormat(date);
            income.setDate(HelperMethod::convetionDateToInt(date));
        }
    }
    cout << "Item name : " << endl;
    income.setItemName(HelperMethod::getLine());
    cout << "Amount : " << endl;
    income.setAmount(HelperMethod::convertionStringToInt(HelperMethod::getLine()));

    incomes.push_back(income);
    incomeXmlFile.addIncomeToFile(income, date);
}


