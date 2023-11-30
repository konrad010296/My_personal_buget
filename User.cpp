#include "User.h"

void User::setUserId(int id){
    userId = id;
}
void User::setUserName(string name){
    userName = name;
}
void User::setUserSurname(string surname){
    userSurname = surname;
}
void User::setUserLogin(string login){
    userLogin = login;
}
void User::setUserPassword(string password){
    userPassword = password;
}

int User::getUserId(){
    return userId;
}
string User::getUserName(){
    return userName;
}
string User::getUserSurname(){
    return userSurname;
}
string User::getUserLogin(){
    return userLogin;
}
string User::getUserPassword(){
    return userPassword;
}
