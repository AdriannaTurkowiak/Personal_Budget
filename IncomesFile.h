#ifndef INCOMESFILE_H
#define INCOMESFILE_H

#include <iostream>
#include <vector>
#include "Markup.h"
#include "Incomes.h"

using namespace std;

class IncomesFile
{
    vector <Incomes> incomes;
    const string INCOME_FILE_NAME;
    int lastIncomeId;

public:
        IncomesFile(string incomeFileName) : INCOME_FILE_NAME(incomeFileName) {
        lastIncomeId = 0;
    }
    void saveIncomeInFile(Incomes income);
    vector <Incomes> readFile(int loggedUserId);
    int getLastIncomeId();

    };
#endif
