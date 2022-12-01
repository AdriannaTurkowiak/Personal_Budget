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

class UserManager {
    vector <User> users;
    User user;
    UserFile userFile;
    int loggedUserId;

public:
    UserManager(string userFileName) : userFile(userFileName) {
        users = userFile.readFile();
        loggedUserId = 0;
    }
    void userRegister();
    void saveUserInFile(User newUser);
    int getNewUserId();
    User getNewUserData();
    bool isThereLogin(string login);
    int getIdOfLoggedUser();
    void userLogIn();
    bool isUserLogged();
    bool logout();
    bool changePassword();
};
#endif
