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

    xml.Save("users.xml");
}
