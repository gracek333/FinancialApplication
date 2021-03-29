#include "UserManager.h"

void UserManager :: registerNewUser()
{
    system("cls");
    cout << endl << "Rejestracja uzytkownika: " << endl << endl;

    User user = inputNewUserData();

    users.push_back(user);

    usersFile.addUserDataToFile(user); //plikZUzytkownikami.dopiszUzytkownikaDoPliku(uzytkownik);

    cout << endl << "Konto zalozono pomyslnie" << endl << endl;
    system("pause");
}

User UserManager :: inputNewUserData()
{
    User user;

    user.setId(getIdForNewUser());
    string name;
    cout << "Podaj imie ";
    cin >> name;
    user.setName(name);
    string surname;
    cout << "Podaj nazwisko ";
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
