#ifndef INCOMES_H
#define INCOMES_H

#include <iostream>
#include <vector>
#include "Markup.h"

using namespace std;

class Incomes {
    int incomeId, userId, amount;
    string date, item;

public:
    Incomes(int incomeId = 0, int userId = 0, int amount = 0, string date = "",string item = "") {
        this -> incomeId = incomeId;
        this -> userId = userId;
        this -> amount = amount;
        this -> date = date;
        this -> item = item;
    }
    void setIncomeId (int newIncomeId);
    void setUserId (int newUserId);
    void setAmount (int newAmount);
    void setDate (string newDate);
    void setItem (string newItem);

    int getIncomeId ();
    int getUserId ();
    int getAmount ();
    string getDate ();
    string getItem ();

};

#endif
