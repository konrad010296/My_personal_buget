#ifndef USERXMLFILE_H
#define USERXMLFILE_H
#include <iostream>
#include "Markup.h"
#include "User.h"
#include <vector>

using namespace std;

class UserXmlFile
{

    const string USERS_FILE_NAME;
    int idOfLastUser;
    vector <User> users;
public:
    UserXmlFile(string usersFileName) : USERS_FILE_NAME(usersFileName)
    {
        idOfLastUser = 0;
    };
    void addUserToXmlFile(User user);
    vector <User> loadUsersFromXmlFile();


};

#endif
