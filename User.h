#ifndef USER_H
#define USER_H
#include <iostream>

using namespace std;

class User{

int userId;
string userName;
string userSurname;
string userLogin;
string userPassword;

public:

void setUserId(int id);
void setUserName(string name);
void setUserSurname(string surname);
void setUserLogin(string login);
void setUserPassword(string password);

int getUserId();
string getUserName();
string getUserSurname();
string getUserLogin();
string getUserPassword();

};
#endif
