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

public:
    void saveIncomeInFile(Incomes income);
    vector <Incomes> readFile();
    };
#endif
