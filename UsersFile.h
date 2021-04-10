#ifndef USERSFILE_H
#define USERSFILE_H

#include <iostream>
#include <vector>
#include <fstream>

#include "User.h"
#include "CommonUsedMethods.h"

using namespace std;

class UsersFile
{
    const string USERS_FILE_NAME;

public:
    UsersFile(string usersFileName) : USERS_FILE_NAME(usersFileName) {};
    string getUsersFileName();
    void addUserDataToFile(User user);
    vector <User> getUsersDataFromFile();
    void saveChangedUserDataToFile(User user);
};

#endif
