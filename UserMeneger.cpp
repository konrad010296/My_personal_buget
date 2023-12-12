#include "UserMeneger.h"

void UserMeneger::registerUser()
{
    bool passwordLength = false;
    system("CLS");
    User user;

    while(!passwordLength)
    {
        cout << "Enter Name : " << endl;
        user.setUserName(HelperMethod::replaceWithCapitalLetter(HelperMethod::getLine()));
        cout << "Enter Surname : " << endl;
        user.setUserSurname(HelperMethod::replaceWithCapitalLetter(HelperMethod::getLine()));
        do
        {
            cout << "Enter Login : " << endl;
            user.setUserLogin(HelperMethod::getLine());
        }
        while (!findSameUserName(user.getUserLogin()));
        cout << "Enter Password : " << endl;
        user.setUserPassword(HelperMethod::getLine());
        passwordLength = HelperMethod::passwordLength(user.getUserPassword());
    }
    lastUserId += 1;
    user.setUserId(lastUserId);
    users.push_back(user);
    userXmlFile.addUserToXmlFile(user);
}

void UserMeneger::logIn()
{
    vector <User> :: iterator it;
    string login,password;
    bool logged = false;
    system("CLS");

    cout << "Enter the login : " << endl;
    login = HelperMethod::getLine();
    cout << "Enter the password : " << endl;
    password = HelperMethod::getLine();

    for(it = users.begin() ; it != users.end() ; ++it)
    {
        if((login == (*it).getUserLogin()) && password == (*it).getUserPassword())
        {
            idOfLoggedUser = (*it).getUserId();
            logged = true;
        }
        else
        {
            logged = false;
        }
        if(logged)
        {
            system("CLS");
            cout << "You have logged in successfully!" << endl;
            Sleep(2000);
            system("CLS");
            return;
        }
    }
    system("CLS");
    cout << "you have entered incorrect data" << endl;
    Sleep(2000);
    system("CLS");
    return;
}


void UserMeneger::changePassword(int loggedUserId)
{
    string newPassword = "";
    string repeatPassword = "";
    int trials = 0;
    bool correctData = false;
    system("CLS");
    while(!correctData)
    {
        cout << "Enter new password : " << endl;
        newPassword = HelperMethod::getLine();
        cout << "Repeat password : " << endl;
        repeatPassword = HelperMethod::getLine();

        if(newPassword != repeatPassword)
        {
            cout << "The entered passwords are different !" << endl;
            Sleep(2000);
            trials++;
            system("CLS");
        }
        if(trials == 3)
        {
            cout << "The number of attempts has been exceeded!" << endl;
            Sleep(2000);
            return;
        }
        if(newPassword == repeatPassword)
        {
            correctData = true;
        }
    }

    for(vector <User> :: iterator it = users.begin() ; it != users.end() ; ++it)
    {

        if(loggedUserId == (*it).getUserId())
            (*it).setUserPassword(newPassword);
    }
    cout << "The password has been changed successfully !" << endl;
    Sleep(2000);
    userXmlFile.addUsersToFileAfterChangePassword(users);
}

int UserMeneger::getLoggedUserId()
{
    return idOfLoggedUser;
}
void UserMeneger::setLogoutUserId()
{
    idOfLoggedUser = 0;
}

bool UserMeneger::findSameUserName(string userLogin)
{

    for(vector <User> :: iterator it = users.begin() ; it != users.end() ; ++it)
    {

        if(userLogin == (*it).getUserLogin())
        {
            cout << "Login is busy!!" << endl;
            Sleep(2000);
            system("CLS");
            return false;
        }
    }
    return true;
}

