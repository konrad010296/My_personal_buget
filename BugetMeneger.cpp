#include "BugetMeneger.h"

void BugetMeneger::addIncome()
{
    string date = "";
    string amount = "";
    system("CLS");
    Income income;
    bool goodFormatDate = false;
    bool goodDateRage = false;
    income.setIncomeId(incomeXmlFile.getLastIncomeId() + 1);
    income.setUserId(IDLOGGEDUSER);
    if(DateMeneger::askAboutDate())
    {
        date = DateMeneger::getCurrentDate();
        income.setDate(DateMeneger::convetionDateToInt(date));
    }
    else
    {
        while(!goodDateRage)
        {
            cout << "Set date in format rrrr-mm-dd : " << endl;
            date = HelperMethod::getLine();

            goodFormatDate = DateMeneger::checkDateFormat(date);
            if(goodFormatDate)
                goodDateRage = DateMeneger::checkDateRage(date);
        }
    }
    income.setDate(DateMeneger::convetionDateToInt(date));
    cout << "Title of income : " << endl;
    income.setItemName(HelperMethod::replaceWithCapitalLetter(HelperMethod::getLine()));
    cout << "Amount : " << endl;
    amount = HelperMethod::getLine();
    amount = HelperMethod::replaceTheCommaWithDot(amount);
    income.setAmount(stof(amount));

    incomes.push_back(income);
    incomeXmlFile.addIncomeToFile(income);
    system("CLS");

    cout << "Your income has been added successfully !" << endl;
    Sleep(2000);
}

void BugetMeneger::addAnExpense()
{
    string date = "";
    string amount = "";
    system("CLS");
    Expense expense;
    bool goodFormatDate = false;
    bool goodDateRage = false;

    expense.setExpenseId(expenseXmlFile.getLastExpenseId() + 1);
    expense.setUserId(IDLOGGEDUSER);
    if(DateMeneger::askAboutDate())
    {
        date = DateMeneger::getCurrentDate();
        expense.setDate(DateMeneger::convetionDateToInt(date));
    }
    else
    {
        while(!goodDateRage)
        {
            cout << "Set date in format rrrr-mm-dd : " << endl;
            date = HelperMethod::getLine();
            goodFormatDate = DateMeneger::checkDateFormat(date);
            if(goodFormatDate)
                goodDateRage = DateMeneger::checkDateRage(date);
        }
    }
    expense.setDate(DateMeneger::convetionDateToInt(date));
    cout << "Item name : " << endl;
    expense.setItemName(HelperMethod::replaceWithCapitalLetter(HelperMethod::getLine()));
    cout << "Amount : " << endl;
    amount = HelperMethod::getLine();
    amount = HelperMethod::replaceTheCommaWithDot(amount);
    expense.setAmount(stof(amount));

    expenses.push_back(expense);
    expenseXmlFile.addExpenseToFile(expense);
    system("CLS");

    cout << "Your expense has been added successfully !" << endl;
    Sleep(2000);
}

void BugetMeneger::balanceSheetForTheCurrentMonth()
{
    string beginningCurrentMonth = "";
    int startMonth = 0;
    int endMonth = 0;
    int lastDayInMonth = 0;
    beginningCurrentMonth = DateMeneger::getCurrentDate();
    beginningCurrentMonth = DateMeneger::changeDateToBeginningMonth(beginningCurrentMonth);
    lastDayInMonth = DateMeneger::calculateDaysInMonth(beginningCurrentMonth);
    startMonth = DateMeneger::convetionDateToInt(beginningCurrentMonth);
    endMonth = DateMeneger::connectLastDayWitchCurrentMounth(startMonth, lastDayInMonth);
    system("CLS");

    printBalance(startMonth, endMonth);
}

void BugetMeneger::balanceFromThePreviousMonth()
{
    int startMonth = 0;
    int endMonth = 0;
    string currentMonth = "";
    string beginningPerviousMonth = "";
    string endOfPerviousMonth = "";
    int lastDayInMonth = 0;

    currentMonth = DateMeneger::getCurrentDate();
    beginningPerviousMonth = DateMeneger::getBeginningPerviousMonth(currentMonth);
    lastDayInMonth = DateMeneger::calculateDaysInMonth(beginningPerviousMonth);

    startMonth = DateMeneger::convetionDateToInt(beginningPerviousMonth);
    endMonth = DateMeneger::connectLastDayWitchCurrentMounth(startMonth,lastDayInMonth);
    system("CLS");

     printBalance(startMonth, endMonth);

}

void BugetMeneger::balanceSheetForTheSelectedPeriod()
{
    string startDate = "";
    string endDate ="";
    int start = 0;
    int finish = 0;
    bool goodFormatStartDate = false;
    bool goodDateStartRage = false;
    bool goodFormatFinishDate = false;
    bool goodDateFinishRage = false;
    system("CLS");

    while(!goodDateStartRage)
    {
        cout << "Enter the starting date in format dddd-mm-dd" << endl;
        startDate = HelperMethod::getLine();
        goodFormatStartDate = DateMeneger::checkDateFormat(startDate);

        if(goodFormatStartDate)
            goodDateStartRage = DateMeneger::checkDateRage(startDate);
    }
    start = DateMeneger::convetionDateToInt(startDate);

    while(!goodDateFinishRage)
    {
        cout << "Enter the finishing date in format dddd-mm-dd" << endl;
        endDate = HelperMethod::getLine();
        goodFormatFinishDate = DateMeneger::checkDateFormat(endDate);

        if(goodFormatFinishDate)
            goodDateFinishRage = DateMeneger::checkDateRage(endDate);
    }
    finish = DateMeneger::convetionDateToInt(endDate);

    if(start > finish)
    {
        cout << "Incorrect dates entered! The start date is older than the end date !" << endl;
        Sleep(2000);
        system("CLS");
        return;
    }
    else
    {
    printBalance(start, finish);
}
}

void BugetMeneger::logOut()
{
    system("CLS");
    cout << "Thank you for using the My Budget App. See you !" << endl;
    Sleep(2000);
}

void BugetMeneger::printBalance(int startDate, int endDate){

    float sumIncomes = 0;
    float sumExpenses = 0;

    sort( incomes.begin( ), incomes.end( ), [ ]( Income& lhs, Income& rhs )
    {
        return lhs.getDate() < rhs.getDate();
    });

    cout << "INCOMES" << endl;
    cout <<  endl;

    for(vector <Income> :: iterator it = incomes.begin() ; it != incomes.end() ; ++it)
    {
        if(((*it).getDate() >= startDate) && ((*it).getDate()) <= endDate)
        {
            sumIncomes += (*it).getAmount();
            cout << "Date : " << DateMeneger::dateSeparatedByDashes((*it).getDate()) << endl;
            cout << "Income Id : " <<(*it).getIncomeId() << endl;
            cout << "User Id : " <<(*it).getUserId() << endl;
            cout << "Title of income : " <<(*it).getItemName() << endl;
            cout << "Amount : " <<(*it).getAmount() << " PLN" << endl;
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
        if(((*it).getDate() >= startDate) && ((*it).getDate()) <= endDate)
        {
            sumExpenses += (*it).getAmount();
            cout << "Date : " << DateMeneger::dateSeparatedByDashes((*it).getDate()) << endl;
            cout << "Expense Id : " <<(*it).getExpenseId() << endl;
            cout << "User Id : " <<(*it).getUserId() << endl;
            cout << "Item Name : " <<(*it).getItemName() << endl;
            cout << "Amount : " <<(*it).getAmount() << " PLN" << endl;
            cout << endl;
        }
    }
    cout << "Sume Of Incomes = " << sumIncomes << " PLN, Sume Of Expenses = " << sumExpenses << " PLN, Total Difference = " << sumIncomes - sumExpenses << " PLN." << endl;
    system("PAUSE");

}
