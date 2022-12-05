#ifndef USERFILE_H
#define USERFILE_H

#include <iostream>
#include <string>
#include <vector>

#include "Markup.h"
#include "User.h"

using namespace std;

class UserFile {

    vector <User> users;
    const string USER_FILE_NAME;

public:
    UserFile(string userFileName) : USER_FILE_NAME(userFileName) {};
    void saveUserInFile(User newUser);
    void savePasswordInFile(int loggedUserID, string newPassword);
    vector <User> readFile();
};
#endif
