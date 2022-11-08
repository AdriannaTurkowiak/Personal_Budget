#ifndef INCOMES_H
#define INCOMES_H

#include <iostream>
#include "Markup.h"

using namespace std;

class Incomes
{
    int incomeId, userId, amount;
    string date, item;

public:
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
