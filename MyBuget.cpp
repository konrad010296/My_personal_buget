#include "MyBuget.h"

void MyBuget::registerUser() {
    userMeneger.registerUser();
}

char MyBuget::logInPanel() {
    cout << "1 - LOG-IN" << endl;
    cout << "2 - REGISTER" << endl;
    cout << "3 - EXIT" << endl;

    char choise;
    choise = getch();

    return choise;
}

void MyBuget::logIn() {
    userMeneger.logIn();
}

int MyBuget::getLoggedUserId(){
    userMeneger.getLoggedUserId();
}
