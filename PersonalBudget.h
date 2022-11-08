#ifndef PERSONALBUDGET_H
#define PERSONALBUDGET_H

#include <iostream>

#include "Markup.h"
#include "User.h"
#include "UserManager.h"

using namespace std;

class PersonalBudget {

    UserManager userManager;

public:
    PersonalBudget(string userFileName) : userManager(userFileName) {};
    void userRegister();
    void incomeRegister();
};

#endif
