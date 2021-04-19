#include "UsersFile.h"
#include "Markup.h"

string UsersFile :: getUsersFileName()
{
    return USERS_FILE_NAME;
}

void UsersFile :: addUserDataToFile(User user)
{
    CMarkup xml;
    bool fileExists = xml.Load( USERS_FILE_NAME );

    if (!fileExists)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Users");
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("User");
    xml.IntoElem();
    xml.AddElem("UserId", user.getId());
    xml.AddElem("Login", user.getLogin());
    xml.AddElem("Password", user.getPassword());
    xml.AddElem("Name", user.getName());
    xml.AddElem("Surname", user.getSurname());

    xml.Save(USERS_FILE_NAME);
}

vector <User> UsersFile :: getUsersDataFromFile()
{
    User user;
    vector <User> users;
    CMarkup xml;
    bool fileExists = xml.Load( USERS_FILE_NAME );
    if (fileExists)
    {
        xml.ResetPos();
        xml.FindElem();
        xml.IntoElem();
        while (xml.FindElem("User"))
        {
            xml.FindChildElem("UserId");
            user.setId(atoi(xml.GetChildData().c_str()));
            xml.FindChildElem("Login");
            user.setLogin(xml.GetChildData());
            xml.FindChildElem("Password");
            user.setPassword(xml.GetChildData());
            xml.FindChildElem("Name");
            user.setName(xml.GetChildData());
            xml.FindChildElem("Surname");
            user.setSurname(xml.GetChildData());

            users.push_back(user);
        }
        xml.Save(USERS_FILE_NAME);
    }

    return users;
}

void UsersFile :: saveChangedUserDataToFile(User user)
{
    CMarkup xml;
    string strFindItem = CommonUsedMethods::convertIntToString(user.getId());
    bool fileExists = xml.Load( USERS_FILE_NAME );

    if (fileExists)
    {
        xml.ResetPos();
        xml.FindElem();
        xml.IntoElem();
        while ( xml.FindElem("User") )
        {
            xml.FindChildElem( "UserId" );
            if ( xml.GetChildData() == strFindItem )
                while (xml.FindChildElem("Password"))
                {
                    xml.SetChildData(user.getPassword());
                }
        }
    }

    else
    {
        cout << "Nie mozna otworzyc pliku " << USERS_FILE_NAME << endl ;
        system("pause");
    }
    xml.Save(USERS_FILE_NAME);
}
