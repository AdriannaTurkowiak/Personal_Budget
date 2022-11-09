#ifndef PERSONALBUDGET_H
#define PERSONALBUDGET_H

#include <iostream>

#include "Markup.h"
#include "User.h"
#include "UserManager.h"
#include "IncomeManager.h"

using namespace std;

class PersonalBudget {

    UserManager userManager;
    IncomeManager *incomeManager;
    const string INCOME_FILE_NAME;

public:
    PersonalBudget(string userFileName, string incomeFileName) : userManager(userFileName), INCOME_FILE_NAME(incomeFileName) {
    incomeManager = NULL;
    };
    ~PersonalBudget(){
    delete incomeManager;
    incomeManager = NULL;
    }
    void userRegister();
    void incomeRegister();
    void logIn();
    bool isUserLogged();

};

#endif
