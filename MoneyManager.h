#ifndef MONEYMANAGER_H
#define MONEYMANAGER_H

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

#include "IncomesFile.h"
#include "ExpensesFile.h"
#include "DateManager.h"


using namespace std;

class MoneyManager {
    vector <Incomes> incomes;
    vector <Expenses> expenses;
    IncomesFile incomesFile;
    ExpensesFile expenseFile;

    int getNewIncomeId();
    Incomes getNewIncomeInfo();
    int getNewExpenseId();
    Expenses getNewExpenseInfo();
    string changeCommaToDot (string amount);
    bool isDateCorrect(string date);
    float sumOfIncomes(string startDate, string endDate);
    float sumOfExpenses(string startDate, string endDate);

    const int LOGGED_USER_ID;

public:
    MoneyManager(string incomeFileName, int loggedUserId, string expenseFileName) : incomesFile(incomeFileName), expenseFile(expenseFileName), LOGGED_USER_ID(loggedUserId) {
        incomes = incomesFile.readFile(LOGGED_USER_ID);
        expenses = expenseFile.readFile(LOGGED_USER_ID);
    }

    void incomeRegister();
    void expenseRegister();
    void currentMonthBalance();
    void lastMonthBalance();
    void selectedPeriodBalance();
};
#endif
