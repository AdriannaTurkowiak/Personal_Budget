#ifndef INCOMESFILE_H
#define INCOMESFILE_H

#include <iostream>
#include "Markup.h"
#include "Incomes.h"

using namespace std;

class IncomesFile
{
    const string INCOME_FILE_NAME;
    vector <Incomes> incomes;
    int lastIncomeId;

public:
       IncomesFile(string incomeFileName) : INCOME_FILE_NAME(incomeFileName) {
        lastIncomeId = 0;
    }
    void saveFile(Incomes newIncome);
    vector <Incomes> readFile(int loggedUserId );
};
#endif
