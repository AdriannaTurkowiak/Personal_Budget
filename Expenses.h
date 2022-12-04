#ifndef EXPENSES_H
#define EXPENSES_H

#include <iostream>
#include <vector>
#include "Markup.h"

using namespace std;

class Expenses {
    int expenseId, userId;
    string amount, item;

public:
    string date;
    Expenses(int expenseId = 0, int userId = 0, string amount = "", string date = "", string item = "") {
        this -> expenseId = expenseId;
        this -> userId = userId;
        this -> amount = amount;
        this -> date = date;
        this -> item = item;
    }
    void setExpenseId (int newExpenseId);
    void setUserId (int newUserId);
    void setAmount (string newAmount);
    void setDate (string newDate);
    void setItem (string newItem);

    int getExpenseId ();
    int getUserId ();
    string getAmount ();
    string getDate ();
    string getItem ();
};

#endif
