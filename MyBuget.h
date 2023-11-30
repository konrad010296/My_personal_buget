#ifndef MYBUGET.H
#define MYBUGET.H
#include <iostream>
#include "UserMeneger.h"
#include "User.h"
#include "UserXmlFile.h"
#include <conio.h>

using namespace std;

class MyBuget {

    UserMeneger userMeneger;

public:
    MyBuget(string usersFileName) : userMeneger(usersFileName){};
    char logInPanel();
    void registerUser();
    char userPanel();
    void logIn();
    int getLoggedUserId();


};
#endif
