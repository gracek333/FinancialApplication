#ifndef USERSFILE_H
#define USERSFILE_H

#include <iostream>
#include <vector>
#include <fstream>

#include "User.h"
#include "CommonUsedMethods.h"
//#include "PlikTekstowy.h"

using namespace std;

class UsersFile
{
    const string USERS_FILE_NAME;
    //Uzytkownik pobierzDaneUzytkownika(string daneJednegoUzytkownikaOddzielonePionowymiKreskami);

public:
    UsersFile(string usersFileName) : USERS_FILE_NAME(usersFileName) {}; // NAZWA_PLIKU(nazwaPliku) {};
    string getUsersFileName();
    void addUserDataToFile(User user);
    vector <User> getUsersDataFromFile();
    void saveChangedUserDataToFile(User user);
//    void zapiszWszystkichUzytkownikowDoPliku(vector <Uzytkownik> &uzytkownicy);*/
};

#endif
