#include "UserXmlFile.h"

void UserXmlFile::addUserToXmlFile(User user)
{
    system("CLS");
    CMarkup xml;

    bool bSuccess = xml.Load (getFileName());

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

    xml.Save(getFileName());
    cout << "You have been registered successfully!" << endl;
    Sleep(2000);

}

vector <User> UserXmlFile::loadUsersFromXmlFile()
{

    vector <User> users;
    User user;
    CMarkup xml;
    xml.Load(getFileName());

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

void UserXmlFile::addUsersToFileAfterChangePassword(vector <User> &vec)
{

    remove(getFileName().c_str());
    CMarkup xml;


    for(vector <User> :: iterator it = vec.begin() ; it != vec.end() ; ++it)
    {
        xml.Load (getFileName());

        bool bSuccess = xml.Load (getFileName());

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
        xml.AddElem( "UserId", (*it).getUserId());
        xml.AddElem( "Login", (*it).getUserLogin() );
        xml.AddElem( "Password", (*it).getUserPassword());
        xml.AddElem( "Name", (*it).getUserName());
        xml.AddElem( "Surname", (*it).getUserSurname());
        xml.Save( getFileName() );
    }
}
