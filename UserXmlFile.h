#ifndef USERXMLFILE_H
#define USERXMLFILE_H
#include <iostream>
#include "Markup.h"
#include "XmlFile.h"
#include "User.h"
#include <vector>
#include <windows.h>

using namespace std;

class UserXmlFile : public XmlFile
{
    int idOfLastUser;
    vector <User> users;
public:
    UserXmlFile(string usersFileName) : XmlFile(usersFileName)
    {
        idOfLastUser = 0;
    };
    void addUserToXmlFile(User user);
    void addUsersToFileAfterChangePassword(vector <User> &vec);
    vector <User> loadUsersFromXmlFile();
};
#endif
