#ifndef MONEYMANAGER_H
#define MONEYMANAGER_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cmath>
#include <iomanip>

#include "Markup.h"
#include "Incomes.h"
#include "Expenses.h"
#include "IncomesFile.h"
#include "ExpensesFile.h"
#include "DateManager.h"
#include "AuxiliaryMethods.h"


using namespace std;

class MoneyManager {
    vector <Incomes> incomes;
    vector <Expenses> expenses;
    Incomes income;
    Expenses expense;
    IncomesFile incomesFile;
    ExpensesFile expenseFile;
    DateManager dateManager;

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
