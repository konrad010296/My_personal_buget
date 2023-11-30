#ifndef USERMENEGER_H
#define USERMENEGER_H
#include <iostream>
#include <windows.h>
#include "User.h"
#include "HelperMethod.h"
#include "UserXmlFile.h"
#include <vector>

using namespace std;

class UserMeneger
{

    UserXmlFile userXmlFile;
    vector <User> users;
    int idOfLoggedUser;

public:
    UserMeneger(string usersFileName) : userXmlFile(usersFileName)
    {
        users = userXmlFile.loadUsersFromXmlFile();
        idOfLoggedUser = 0;
    }
    void registerUser();
    void logIn();
    int getLoggedUserId();

};
#endif
