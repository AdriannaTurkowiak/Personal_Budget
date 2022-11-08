#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#include "Markup.h"
#include "User.h"
#include "Incomes.h"
#include "IncomesFile.h"
#include "UserFile.h"

using namespace std;

class UserManager
{
    vector <User> users;
    vector <Incomes> incomes;
    User user;
    Incomes income;
    UserFile userFile;
    IncomesFile incomesFile;

    public:
    UserManager(string userFileName) : userFile(userFileName) {
    users = userFile.readFile();
    incomes = incomesFile.readFile();
    }
    void userRegister();
    void saveUserInFile(User newUser);
    int getNewUserId();
    User getNewUserData();
    bool isThereLogin(string login);
    void incomeRegister();
    int getNewIncomeId();
    Incomes getNewIncomeInfo();

};
#endif
