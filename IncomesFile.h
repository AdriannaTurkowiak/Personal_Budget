#ifndef INCOMESFILE_H
#define INCOMESFILE_H

#include <iostream>
#include <vector>
#include "Markup.h"
#include "Incomes.h"

using namespace std;

class IncomesFile {
    vector <Incomes> incomes;
    const string INCOME_FILE_NAME;

public:
    IncomesFile(string incomeFileName) : INCOME_FILE_NAME(incomeFileName) {
    }
    void saveIncomeInFile(Incomes income);
    vector <Incomes> readFile(int loggedUserId);
};
#endif
