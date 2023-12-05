#include "ExpensesXmlFile.h"

void ExpensesXmlFile::addExpenseToFile(Expense expense, string date, string amount)
{
    CMarkup xml;

    bool bSuccess = xml.Load (EXPENSES_FILE_NAME);

    if(!bSuccess)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem( "Expenses" );
    }
    xml.FindElem();
    xml.IntoElem();
    xml.AddElem( "Expense" );
    xml.IntoElem();
    xml.AddElem( "ExpenseId", expense.getExpenseId());
    xml.AddElem( "UserId", expense.getUserId());
    xml.AddElem( "Date", date);
    xml.AddElem( "ItemName", expense.getItemName());
    xml.AddElem( "Amount", amount);
    system("PAUSE");


    xml.Save( EXPENSES_FILE_NAME );

}

vector <Expense> ExpensesXmlFile::readExpensesFromFile(int idLoggedUser)
{
    vector <Expense> expenses;
    Expense expense;

    CMarkup xml;
    xml.Load( EXPENSES_FILE_NAME );

    xml.FindElem();
    xml.IntoElem();
    while ( xml.FindElem("Expense") )
    {
        xml.IntoElem();
        xml.FindElem( "ExpenseId" );

        expense.setExpenseId(atoi(xml.GetData().c_str()));
        lastExpenseId = atoi(xml.GetData().c_str());
        xml.FindElem( "UserId" );
        expense.setUserId(atoi(xml.GetData().c_str()));
        xml.FindElem( "Date" );
        expense.setDate(HelperMethod::convetionDateToInt(xml.GetData()));
        xml.FindElem( "ItemName" );
        expense.setItemName(xml.GetData());
        xml.FindElem( "Amount" );
        expense.setAmount(atoi(xml.GetData().c_str()));

        if(expense.getUserId() == idLoggedUser)
        {
            expenses.push_back(expense);
        }
        xml.OutOfElem();
    }
    return expenses;

}
