#include <iostream>
#include "Markup.h"
#include "MyBuget.h"
using namespace std;

int main()
{
    MyBuget myBuget("UsersFile.xml");
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
}
