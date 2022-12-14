#ifndef EXPENSESFILE_H
#define EXPENSESFILE_H

#include <iostream>
#include <vector>

#include "Expenses.h"

using namespace std;

class ExpensesFile {
    vector <Expenses> expenses;
    const string EXPENSES_FILE_NAME;

public:
    ExpensesFile(string expenseFileName) : EXPENSES_FILE_NAME(expenseFileName) {
    }
    void saveExpenseInFile(Expenses expense);
    vector <Expenses> readFile(int loggedUserId);
};
#endif
