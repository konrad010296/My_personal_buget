#include <iostream>
#include "Markup.h"
#include "MyBuget.h"

using namespace std;

int main()
{
    MyBuget myBuget("UsersFile.xml", "incomes.xml","expenses.xml");
    while(true){
    while(myBuget.getLoggedUserId()  == 0)
    {
        system("CLS");
        char choise = myBuget.logInPanel();

        switch(choise)
        {
        case '1': myBuget.logIn(); break;
        case '2': myBuget.registerUser(); break;
        case '3': exit(0);break;
        }
    }

    while(myBuget.getLoggedUserId()  != 0)
    {
        char choise = myBuget.userPanel();

        switch(choise){
        case '1' : myBuget.addIncome(); break;
        case '2' : myBuget.addAnExpense(); break;
        case '3' : myBuget.balanceSheetForTheCurrentMonth(); break;
        case '4' : myBuget.balanceFromThePreviousMonth(); break;
        case '5' : myBuget.balanceSheetForTheSelectedPeriod(); break;
        case '6' : myBuget.changePassword(myBuget.getLoggedUserId()); break;
        case '7' : myBuget.logOut(); break;
        }
    }
    }
    return 0;
}
