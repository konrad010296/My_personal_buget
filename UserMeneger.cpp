#include "UserMeneger.h"

void UserMeneger::registerUser() {
    system("CLS");
    User user;

    cout << "Enter Name : " << endl;
    user.setUserName(HelperMethod::replaceWithCapitalLetter(HelperMethod::getLine()));
    cout << "Enter Surname : " << endl;
    user.setUserSurname(HelperMethod::replaceWithCapitalLetter(HelperMethod::getLine()));
    cout << "Enter Login : " << endl;
    user.setUserLogin(HelperMethod::getLine());
    cout << "Enter Password : " << endl;
    user.setUserPassword(HelperMethod::getLine());
    lastUserId += 1;
    user.setUserId(lastUserId);
    users.push_back(user);
    userXmlFile.addUserToXmlFile(user);
}

void UserMeneger::logIn() {
    vector <User> :: iterator it;
    string login,password;
    bool logged = false;
    system("CLS");

    cout << "Enter the login : " << endl;
    login = HelperMethod::getLine();
    cout << "Enter the password : " << endl;
    password = HelperMethod::getLine();

    for(it = users.begin() ; it != users.end() ; ++it) {
        if((login == (*it).getUserLogin()) && password == (*it).getUserPassword()) {
            idOfLoggedUser = (*it).getUserId();
            logged = true;
        } else {
            logged = false;
        }
        if(logged) {
            cout << "You have logged in successfully!" << endl;
            Sleep(2000);
            return;
        }
    }
    cout << "you have entered incorrect data" << endl;
    Sleep(2000);
    return;
}

int UserMeneger::getLoggedUserId() {
    return idOfLoggedUser;
}
