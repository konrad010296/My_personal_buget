#include "BugetMeneger.h"

void BugetMeneger::addIncome()
{
    string date = "";
    string amount = "";
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
    income.setItemName(HelperMethod::replaceWithCapitalLetter(HelperMethod::getLine()));
    cout << "Amount : " << endl;
    amount = HelperMethod::getLine();
    amount = HelperMethod::replaceTheCommaWithDot(amount);
    income.setAmount(HelperMethod::convertionStringToFloat(amount));

    incomes.push_back(income);
    incomeXmlFile.addIncomeToFile(income, date, amount);
}

void BugetMeneger::addAnExpense()
{
    string date = "";
    string amount = "";
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
    expense.setItemName(HelperMethod::replaceWithCapitalLetter(HelperMethod::getLine()));
    cout << "Amount : " << endl;
    amount = HelperMethod::getLine();
    amount = HelperMethod::replaceTheCommaWithDot(amount);
    expense.setAmount(HelperMethod::convertionStringToFloat(amount));

    expenses.push_back(expense);
    expenseXmlFile.addExpenseToFile(expense, date, amount);
}

void BugetMeneger::balanceSheetForTheCurrentMonth()
{
    vector <Income> :: iterator it;
    int startMonth = 0;
    int endMonth = 0;
    string beginningCurrentMonth = "";
    string year = "";
    string month = "";
    int yearDigit = 0;
    int monthDigit = 0;
    int daysInMonth = 0;
    string endOfCurrentMonth = "";
    float sumIncomes = 0;
    float sumExpenses = 0;

    beginningCurrentMonth = HelperMethod::getCurrentDate();
    year = beginningCurrentMonth.substr(0, 4);
    month = beginningCurrentMonth.substr(5, 2);
    yearDigit = HelperMethod::convertionStringToInt(year);
    monthDigit = HelperMethod::convertionStringToInt(month);
    daysInMonth = HelperMethod::calculateDaysInMonth(yearDigit, monthDigit);
    beginningCurrentMonth = HelperMethod::changeDateToBeginningMonth(beginningCurrentMonth);
    endOfCurrentMonth = HelperMethod::connectLastDayWitchCurrentMounth(beginningCurrentMonth, daysInMonth);

    startMonth = HelperMethod::convetionDateToInt(beginningCurrentMonth);
    endMonth = HelperMethod::convetionDateToInt(endOfCurrentMonth);

    system("CLS");

    cout << "INCOMES" << endl;
    cout <<  endl;
    sort( incomes.begin( ), incomes.end( ), [ ]( Income& lhs, Income& rhs )
    {
        return lhs.getDate() < rhs.getDate();
    });

    for(vector <Income> :: iterator it = incomes.begin() ; it != incomes.end() ; ++it)
    {
        sumIncomes += (*it).getAmount();
        if(((*it).getDate() >= startMonth) && ((*it).getDate()) <= endMonth)
        {
            cout << "Date : " << HelperMethod::dateSeparatedByDashes((*it).getDate()) << endl;
            cout << "Income Id : " <<(*it).getIncomeId() << endl;
            cout << "User Id : " <<(*it).getUserId() << endl;
            cout << "Item Name : " <<(*it).getItemName() << endl;
            cout << "Amount : " <<(*it).getAmount() << endl;
            cout << endl;
        }
    }

    sort( expenses.begin( ), expenses.end( ), [ ]( Expense& lhs, Expense& rhs )
    {
        return lhs.getDate() < rhs.getDate();
    });

    cout << "EXPENSES" << endl;
    cout <<  endl;
    for(vector <Expense> :: iterator it = expenses.begin() ; it != expenses.end() ; ++it)
    {
        sumExpenses += (*it).getAmount();
        if(((*it).getDate() >= startMonth) && ((*it).getDate()) <= endMonth)
        {
            cout << "Date : " << HelperMethod::dateSeparatedByDashes((*it).getDate()) << endl;
            cout << "Income Id : " <<(*it).getExpenseId() << endl;
            cout << "User Id : " <<(*it).getUserId() << endl;
            cout << "Item Name : " <<(*it).getItemName() << endl;
            cout << "Amount : " <<(*it).getAmount() << endl;
            cout << endl;
        }
    }
    cout << "Sume Of Incomes = " << sumIncomes << ", Sume Of Expenses = " << sumExpenses << ", Total Difference = " << sumIncomes - sumExpenses << endl;
    system("PAUSE");

}

void BugetMeneger::balanceFromThePreviousMonth()
{
    vector <Income> :: iterator it;
    int startMonth = 0;
    int endMonth = 0;
    string currentMonth = "";
    string beginningPerviousMonth = "";
    string endOfPerviousMonth = "";
    string year = "";
    string month = "";
    int yearDigit = 0;
    int monthDigit = 0;
    int daysInMonth = 0;
    float sumIncomes = 0;
    float sumExpenses = 0;


    currentMonth = HelperMethod::getCurrentDate();
    year = currentMonth.substr(0, 4);
    month = currentMonth.substr(5, 2);
    yearDigit = HelperMethod::convertionStringToInt(year);
    monthDigit = HelperMethod::convertionStringToInt(month);
    if(monthDigit == 1)
    {
        yearDigit = yearDigit - 1;
        monthDigit = 12;
    }
    else
        monthDigit = monthDigit - 1;

    if(monthDigit < 10)
    {
        month = "0" + to_string(monthDigit) + "-";
        year = to_string(yearDigit) + "-";
    }
    else
    {
        month = to_string(monthDigit)+ "-";
        year = to_string(yearDigit)+ "-";
    }
    daysInMonth = HelperMethod::calculateDaysInMonth(yearDigit, monthDigit);
    beginningPerviousMonth = beginningPerviousMonth + year + month + "01";

    endOfPerviousMonth = HelperMethod::connectLastDayWitchCurrentMounth(beginningPerviousMonth, daysInMonth);
    startMonth = HelperMethod::convetionDateToInt(beginningPerviousMonth);
    endMonth = HelperMethod::convetionDateToInt(endOfPerviousMonth);

    system("CLS");

    cout << "INCOMES" << endl;
    cout <<  endl;
    sort( incomes.begin( ), incomes.end( ), [ ]( Income& lhs, Income& rhs )
    {
        return lhs.getDate() < rhs.getDate();
    });

    for(vector <Income> :: iterator it = incomes.begin() ; it != incomes.end() ; ++it)
    {
        sumIncomes += (*it).getAmount();
        if(((*it).getDate() >= startMonth) && ((*it).getDate()) <= endMonth)
        {
            cout << "Date : " << HelperMethod::dateSeparatedByDashes((*it).getDate()) << endl;
            cout << "Income Id : " <<(*it).getIncomeId() << endl;
            cout << "User Id : " <<(*it).getUserId() << endl;
            cout << "Item Name : " <<(*it).getItemName() << endl;
            cout << "Amount : " <<(*it).getAmount() << endl;
            cout << endl;
        }
    }

    sort( expenses.begin( ), expenses.end( ), [ ]( Expense& lhs, Expense& rhs )
    {
        return lhs.getDate() < rhs.getDate();
    });

    cout << "EXPENSES" << endl;
    cout <<  endl;
    for(vector <Expense> :: iterator it = expenses.begin() ; it != expenses.end() ; ++it)
    {
        sumExpenses += (*it).getAmount();
        if(((*it).getDate() >= startMonth) && ((*it).getDate()) <= endMonth)
        {
            cout << "Date : " << HelperMethod::dateSeparatedByDashes((*it).getDate()) << endl;
            cout << "Income Id : " <<(*it).getExpenseId() << endl;
            cout << "User Id : " <<(*it).getUserId() << endl;
            cout << "Item Name : " <<(*it).getItemName() << endl;
            cout << "Amount : " <<(*it).getAmount() << endl;
            cout << endl;
        }
    }
    cout << "Sume Of Incomes = " << sumIncomes << ", Sume Of Expenses = " << sumExpenses << ", Total Difference = " << sumIncomes - sumExpenses << endl;
    system("PAUSE");

}
