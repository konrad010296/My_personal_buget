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
    int lastUserId;

public:
    UserMeneger(string usersFileName) : userXmlFile(usersFileName)
    {
        users = userXmlFile.loadUsersFromXmlFile();
        idOfLoggedUser = 0;
        lastUserId = 0;
        if(users.size() == 0)
            lastUserId = 0;
        else
            lastUserId = users[users.size() - 1].getUserId();
    }
    void registerUser();
    void logIn();
    int getLoggedUserId();

};
#endif
