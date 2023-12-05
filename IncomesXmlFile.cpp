#include "IncomesXmlFile.h"

void IncomesXmlFile::addIncomeToFile(Income incomes, string date, string amount)
{

    CMarkup xml;

    bool bSuccess = xml.Load (INCOMES_FILE_NAME);

    if(!bSuccess)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem( "Incomes" );
    }
    xml.FindElem();
    xml.IntoElem();
    xml.AddElem( "Income" );
    xml.IntoElem();
    xml.AddElem( "IncomeId", incomes.getIncomeId());
    xml.AddElem( "UserId", incomes.getUserId());
    xml.AddElem( "Date", date);
    xml.AddElem( "ItemName", incomes.getItemName());
    xml.AddElem( "Amount", amount);


    xml.Save( INCOMES_FILE_NAME );

}


vector <Income> IncomesXmlFile::loadIncomesFromXmlFile(int idLoggedUser)
{
    vector <Income> incomes;
    Income income;

    CMarkup xml;
    xml.Load( INCOMES_FILE_NAME );

    xml.FindElem();
    xml.IntoElem();
    while ( xml.FindElem("Income") )
    {
        xml.IntoElem();
        xml.FindElem( "IncomeId" );

        income.setIncomeId(atoi(xml.GetData().c_str()));
        lastIncomeId = atoi(xml.GetData().c_str());
        xml.FindElem( "UserId" );
        income.setUserId(atoi(xml.GetData().c_str()));
        xml.FindElem( "Date" );
        income.setDate(HelperMethod::convetionDateToInt(xml.GetData()));
        xml.FindElem( "ItemName" );
        income.setItemName(xml.GetData());
        xml.FindElem( "Amount" );
        income.setAmount(atoi(xml.GetData().c_str()));

        if(income.getUserId() == idLoggedUser)
        {
            incomes.push_back(income);
        }
        xml.OutOfElem();
    }
    return incomes;

}

