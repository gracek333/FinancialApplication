#include "UserManager.h"

void UserManager :: registerNewUser()
{
    system("cls");
    cout  << "Rejestracja uzytkownika: " << endl << endl;

    User user = inputNewUserData();

    users.push_back(user);

    usersFile.addUserDataToFile(user);

    cout << endl << "Konto zalozono pomyslnie!" << endl << endl;
    system("pause");
}

User UserManager :: inputNewUserData()
{
    User user;

    user.setId(getIdForNewUser());
    string name;
    cout << "Podaj imie: ";
    cin >> name;
    user.setName(name);
    string surname;
    cout << "Podaj nazwisko: ";
    cin >> surname;
    user.setSurname(surname);

    string login;

    do
    {
        cout << "Podaj login: ";
        cin >> login;
        user.setLogin(login);
    } while (isLoginExisting(user.getLogin()) == true);

    string password;
    cout << "Podaj haslo: ";
    cin >> password;
    user.setPassword(password);

    return user;
}

int UserManager :: getIdForNewUser()
{
    if (users.empty() == true)
        return 1;
    else
        return users.back().getId() + 1;
}

bool UserManager :: isLoginExisting(string login)
{
    for (int i = 0; i< users.size(); i++)
    {
        if (users[i].getLogin() == login)
        {
            cout << endl << "Istnieje uzytkownik o takim loginie." << endl;
            return true;
        }
    }
    return false;
}

void UserManager :: printAllUsers()
{
    for (int i = 0; i< users.size(); i++)
    {
        cout << users[i].getId() << endl;
        cout << users[i].getName() << endl;
        cout << users[i].getSurname() << endl;
        cout << users[i].getLogin() << endl;
        cout << users[i].getPassword() << endl;
    }
}

void UserManager :: logInUser()
{
    string login = "", password = "";

    cout << endl << "Podaj login: ";
    login = CommonUsedMethods::getPhrase();

    vector <User>::iterator itr = users.begin();

    while (itr != users.end())
    {
        if (itr -> getLogin() == login)
        {
            for (int numberOfAttempts = 3; numberOfAttempts > 0; numberOfAttempts--)
            {
                cout << "Podaj haslo. Pozostalo prob: " << numberOfAttempts << ": ";
                password = CommonUsedMethods::getPhrase();

                if (itr -> getPassword() == password)
                {
                    loggedInUserId = itr -> getId();
                    cout << endl << "Zalogowales sie." << endl << endl;
                    system("pause");
                    return;
                }
            }
            cout << "Wprowadzono 3 razy bledne haslo." << endl;
            system("pause");
            return;
        }
        itr++;
    }
    cout << "Nie ma uzytkownika z takim loginem" << endl << endl;
    system("pause");
    return;
}

void UserManager :: logOutUser()
{
    loggedInUserId = 0;
}

void UserManager :: changeLoggedInUserPassword()
{
    system("cls");
    User user;
    cout << endl << "Zmiana hasla: " << endl << endl;
    string newPassword = "";
    cout << "Podaj nowe haslo: ";
    cin >> newPassword;

    for (int i = 0; i < users.size(); i++)
    {
        if (users[i].getId() == getLoggedInUserId())
        {
            users[i].setPassword(newPassword);
            cout << "Haslo zostalo zmienione." << endl << endl;
            user = users[i];
            system("pause");
        }
    }
    usersFile.saveChangedUserDataToFile(user);
}

int UserManager :: getLoggedInUserId()
{
    return loggedInUserId;
}

bool UserManager :: isUserLoggedIn()
{
    if (loggedInUserId > 0)
        return true;
    else
        return false;
}
