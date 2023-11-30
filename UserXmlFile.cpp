#include "UserXmlFile.h"

void UserXmlFile::addUserToXmlFile(User user)
{

    CMarkup xml;

    bool bSuccess = xml.Load (USERS_FILE_NAME);

    idOfLastUser++;
    if(!bSuccess)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem( "Users" );
    }
    xml.FindElem();
    xml.IntoElem();
    xml.AddElem( "User" );
    xml.IntoElem();
    xml.AddElem( "UserId", idOfLastUser );
    xml.AddElem( "Login", user.getUserLogin() );
    xml.AddElem( "Password", user.getUserPassword() );
    xml.AddElem( "Name", user.getUserName() );
    xml.AddElem( "Surname", user.getUserSurname() );


    xml.Save( USERS_FILE_NAME );

}

vector <User> UserXmlFile::loadUsersFromXmlFile()
{

    vector <User> users;
    User user;
    CMarkup xml;
    xml.Load( USERS_FILE_NAME );

    xml.FindElem();
    xml.IntoElem();
    while ( xml.FindElem("User") )
    {
        xml.IntoElem();
        xml.FindElem( "UserId" );

        user.setUserId(atoi(xml.GetData().c_str()));
        idOfLastUser = atoi(xml.GetData().c_str());
        xml.FindElem( "Login" );
        user.setUserLogin(xml.GetData());
        xml.FindElem( "Password" );
        user.setUserPassword(xml.GetData());
        xml.FindElem( "Name" );
        user.setUserName(xml.GetData());
        xml.FindElem( "Surname" );
        user.setUserSurname(xml.GetData());

        users.push_back(user);
        xml.OutOfElem();
    }
    return users;

}
