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
    int getNewUserId();
    User getNewUserData();
    void saveUserInFile(User newUser);
    bool isThereLogin(string login);

public:
    UserManager(string userFileName) : userFile(userFileName) {
        users = userFile.readFile();
        loggedUserId = 0;
    }
    void userRegister();
    int getIdOfLoggedUser();
    void userLogIn();
    bool isUserLogged();
    void logout();
    void changePassword();
};
#endif
