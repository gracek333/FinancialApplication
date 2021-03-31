#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>

#include "User.h"
#include "UsersFile.h"

using namespace std;

class UserManager
{
    int loggedInUserId;
    vector <User> users;
    UsersFile usersFile;

    User inputNewUserData();
    int getIdForNewUser();
    bool isLoginExisting(string login);

public:
    UserManager(string usersFileName) : usersFile(usersFileName)
    {
        loggedInUserId = 0;
        users = usersFile.getUsersDataFromFile();
    };

    void registerNewUser();
    void printAllUsers();
    void logInUser();
   /* void zmianaHaslaZalogowanegoUzytkownika();
    void wylogowanieUzytkownika();
    bool czyUzytkownikJestZalogowany();
    int pobierzIdZalogowanegoUzytkownika();*/
};

#endif
