#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#include "Markup.h"
#include "User.h"
#include "UserFile.h"

using namespace std;

class UserManager
{
    vector <User> users;
    User user;
    UserFile userFile;

    public:
    UserManager(string userFileName) : userFile(userFileName) {
    users = userFile.readFile();
    }
    void userRegister();
    void saveUserInFile(User newUser);
    int getNewUserId();
    User getNewUserData();
    bool isThereLogin(string login);
};
#endif
