#ifndef PERSONALBUDGET_H
#define PERSONALBUDGET_H

#include <iostream>

#include "Markup.h"
#include "User.h"
#include "UserManager.h"
#include "MoneyManager.h"
#include "DateManager.h"
#include "AuxiliaryMethods.h"

using namespace std;

class PersonalBudget {

    UserManager userManager;
    MoneyManager *moneyManager;
    const string INCOME_FILE_NAME;
    const string EXPENSE_FILE_NAME;
    DateManager date;

public:
    PersonalBudget(string userFileName, string incomeFileName, string expenseFileName) : userManager(userFileName), INCOME_FILE_NAME(incomeFileName), EXPENSE_FILE_NAME(expenseFileName) {
        moneyManager = NULL;
    };
    ~PersonalBudget() {
        delete moneyManager;
        moneyManager = NULL;
    }
    void userRegister();
    void incomeRegister();
    void expenseRegister();
    void logIn();
    bool isUserLogged();
    void logout();
    char userMenu();
    void currentMonthBalance();
    void lastMonthBalance();
    void selectedPeriodBalance();
    void changePassword();
    char mainMenu();
};

#endif
