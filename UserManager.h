#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>

#include "User.h"

using namespace std;

class UserManager
{
    int loggedInUserId;
    vector <User> users;
    //PlikZUzytkownikami plikZUzytkownikami;

    User inputNewUserData();
    int getIdForNewUser();
    bool isLoginExisting(string login);

public:
    UserManager()
    {
        loggedInUserId = 0;
    };

    void registerNewUser();
    /*void wypiszWszystkichUzytkownikow();
    void logowanieUzytkownika();
    void zmianaHaslaZalogowanegoUzytkownika();
    void wylogowanieUzytkownika();
    bool czyUzytkownikJestZalogowany();
    int pobierzIdZalogowanegoUzytkownika();*/
};

#endif
