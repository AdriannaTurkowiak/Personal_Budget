#ifndef INCOMEMANAGER_H
#define INCOMEMANAGER_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#include "Markup.h"
#include "Incomes.h"
#include "IncomesFile.h"

using namespace std;

class IncomeManager
{
    vector <Incomes> incomes;
    Incomes income;
    IncomesFile incomesFile;
    const int LOGGED_USER_ID;


    public:
    IncomeManager(string incomeFileName, int loggedUserId) : incomesFile(incomeFileName), LOGGED_USER_ID(loggedUserId) {
    incomes = incomesFile.readFile(LOGGED_USER_ID);
    }
    void incomeRegister();
    int getNewIncomeId();
    Incomes getNewIncomeInfo();

};
#endif
