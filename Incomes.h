#ifndef INCOMES_H
#define INCOMES_H

#include <iostream>
#include <vector>
#include "Markup.h"

using namespace std;

class Incomes {
    int incomeId, userId;
    string amount, item;

public:
    string date;
    Incomes(int incomeId = 0, int userId = 0, string amount = "", string date = "",string item = "") {
        this -> incomeId = incomeId;
        this -> userId = userId;
        this -> amount = amount;
        this -> date = date;
        this -> item = item;
    }
    void setIncomeId (int newIncomeId);
    void setUserId (int newUserId);
    void setAmount (string newAmount);
    void setDate (string newDate);
    void setItem (string newItem);

    int getIncomeId ();
    int getUserId ();
    string getAmount ();
    string getDate ();
    string getItem ();
};

#endif
