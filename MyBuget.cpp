#include "MyBuget.h"

void MyBuget::registerUser()
{
    userMeneger.registerUser();
}

char MyBuget::logInPanel()
{
    cout << "1 - LOG-IN" << endl;
    cout << "2 - REGISTER" << endl;
    cout << "3 - EXIT" << endl;

    return getch();
}

void MyBuget::logIn()
{
    userMeneger.logIn();
    int idLoggedUser = userMeneger.getLoggedUserId();

    if(idLoggedUser != 0)
    {
        bugetMeneger = new BugetMeneger(INCOMES_FILE_NAME, EXPENSES_FILE_NAME, idLoggedUser);
    }
}

int MyBuget::getLoggedUserId()
{
    userMeneger.getLoggedUserId();
}

char MyBuget::userPanel()
{

    system("CLS");
    cout << "1 - Add income" << endl;
    cout << "2 - Add an expense" << endl;
    cout << "3 - Balance sheet for the current month" << endl;
    cout << "4 - Balance from the previous month" << endl;
    cout << "5 - Balance sheet for the selected period" << endl;
    cout << "6 - Change Password" << endl;
    cout << "7 - Log out" << endl;

    char choise;
    choise = getch();

    return choise;
}
void MyBuget::addIncome()
{
    bugetMeneger->addIncome();
}

void MyBuget::addAnExpense()
{
    bugetMeneger->addAnExpense();
}

void MyBuget::balanceSheetForTheCurrentMonth()
{
    bugetMeneger->balanceSheetForTheCurrentMonth();
}

void MyBuget::balanceFromThePreviousMonth()
{
    bugetMeneger->balanceFromThePreviousMonth();
}

void MyBuget::balanceSheetForTheSelectedPeriod()
{
    {
        bugetMeneger->balanceSheetForTheSelectedPeriod();
    }
}
void MyBuget::logOut()
{
    bugetMeneger->logOut();
    delete bugetMeneger;
    bugetMeneger = NULL;
    userMeneger.setLogoutUserId();
}

void MyBuget::changePassword(int loggedUserId)
{
    userMeneger.changePassword(loggedUserId);
}
