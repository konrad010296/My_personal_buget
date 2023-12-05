#include "BugetMeneger.h"

void BugetMeneger::addIncome()
{
    string date = "";
    system("CLS");
    Income income;
    bool goodFormatDate = false;
    bool goodDateRage = false;

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
        while(!goodDateRage)
        {
            cout << "Set date in format rrrr-mm-dd : " << endl;
            date = HelperMethod::getLine();

            goodFormatDate = HelperMethod::checkDateFormat(date);
            if(goodFormatDate)
                goodDateRage = HelperMethod::checkDateRage(date);
        }
    }
    income.setDate(HelperMethod::convetionDateToInt(date));
    cout << "Item name : " << endl;
    income.setItemName(HelperMethod::getLine());
    cout << "Amount : " << endl;
    income.setAmount(HelperMethod::convertionStringToInt(HelperMethod::getLine()));

    incomes.push_back(income);
    incomeXmlFile.addIncomeToFile(income, date);
}

void BugetMeneger::addAnExpense()
{
    string date = "";
    system("CLS");
    Expense expense;
     bool goodFormatDate = false;
    bool goodDateRage = false;

    if(expenses.size() == 0)
        expense.setExpenseId(1);
    else
        expense.setExpenseId(incomes[expenses.size() - 1].getIncomeId() + 1);
    expense.setUserId(idLoggedUser);
    if(HelperMethod::askAboutDate())
    {
        date = HelperMethod::getCurrentDate();
        expense.setDate(HelperMethod::convetionDateToInt(date));
    }
    else
    {
        while(!goodDateRage)
        {
            cout << "Set date in format rrrr-mm-dd : " << endl;
            date = HelperMethod::getLine();
            goodFormatDate = HelperMethod::checkDateFormat(date);
            if(goodFormatDate)
                goodDateRage = HelperMethod::checkDateRage(date);
        }
    }
    expense.setDate(HelperMethod::convetionDateToInt(date));
    cout << "Item name : " << endl;
    expense.setItemName(HelperMethod::getLine());
    cout << "Amount : " << endl;
    expense.setAmount(HelperMethod::convertionStringToInt(HelperMethod::getLine()));

    expenses.push_back(expense);
    expenseXmlFile.addExpenseToFile(expense, date);

}

