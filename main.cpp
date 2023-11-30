#include <iostream>
#include "Markup.h"
#include "MyBuget.h"

using namespace std;

int main() {
    MyBuget myBuget("UsersFile.xml", "incomes.xml" ,"expenses.xml");
    while(myBuget.getLoggedUserId()  == 0) {
        system("CLS");
        char choise = myBuget.logInPanel();

        switch(choise) {
        case '1': {
            myBuget.logIn();
        }
        break;
        case '2': {
            myBuget.registerUser();
        }
        break;
        case '3': {
            exit(0);
        }
        break;
        }
    }
    while(myBuget.getLoggedUserId()  != 0) {
        char choise = myBuget.userPanel();


        switch(choise) {
        case '1' : {

        }
        break;
        case '2' : {

        }
        break;
        case '3' : {

        }
        break;
        case '4' : {

        }
        break;
        case '5' : {

        }
        break;
        case '6' : {

        }
        break;
        case '7' : {
            exit(0);
        }
        break;
        }
    }
    return 0;
}
