#include "IncomesXmlFile.h"

void IncomesXmlFile::addIncomeToFile(Income incomes)
{

    CMarkup xml;
    lastIncomeId = lastIncomeId + 1;

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
    xml.AddElem( "IncomeId", lastIncomeId);
    xml.AddElem( "UserId", incomes.getUserId());
    xml.AddElem( "Date", DateMeneger::dateSeparatedByDashes(incomes.getDate()));
    xml.AddElem( "ItemName", incomes.getItemName());
    xml.AddElem( "Amount", HelperMethod::convertAmountToString(incomes.getAmount()));

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

        lastIncomeId = atoi(xml.GetData().c_str());
        income.setIncomeId(lastIncomeId);
        xml.FindElem( "UserId" );
        income.setUserId(atoi(xml.GetData().c_str()));
        xml.FindElem( "Date" );
        income.setDate(DateMeneger::convetionDateToInt(xml.GetData()));
        xml.FindElem( "ItemName" );
        income.setItemName(xml.GetData());
        xml.FindElem( "Amount" );
        income.setAmount(stof(xml.GetData()));

        if(income.getUserId() == idLoggedUser)
        {
            incomes.push_back(income);
        }
        xml.OutOfElem();
    }
    return incomes;

}

int IncomesXmlFile::getLastIncomeId(){
return lastIncomeId;
}
