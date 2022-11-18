#ifndef EXPENSESFILE_H
#define EXPENSESFILE_H

#include <iostream>
#include <vector>
#include "Markup.h"
#include "Date.h"
#include "Expenses.h"

using namespace std;

class ExpensesFile {
    vector <Expenses> expenses;
    const string EXPENSES_FILE_NAME;
    int lastExpenseId;

public:
    ExpensesFile(string expenseFileName) : EXPENSES_FILE_NAME(expenseFileName) {
        lastExpenseId = 0;
    }
    void saveExpenseInFile(Expenses expense);
    vector <Expenses> readFile(int loggedUserId);
    int getlastExpenseId();
    void showVector(vector<Expenses> expenses);
    string convertIntToString(int number);

};
#endif
