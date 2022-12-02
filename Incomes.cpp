#include "Incomes.h"

void Incomes::setIncomeId (int newIncomeId) {
    if(newIncomeId >= 0)
        incomeId = newIncomeId;
}

void Incomes::setUserId (int newUserId) {
    if(newUserId >= 0)
        userId = newUserId;
}

void Incomes::setAmount (string newAmount) {
    amount = newAmount;
}

void Incomes::setDate (string newDate) {
    date = newDate;
}

void Incomes::setItem (string newItem) {
    item = newItem;
}

int Incomes::getIncomeId() {
    return incomeId;
}

int Incomes::getUserId() {
    return userId;
}

string Incomes::getAmount() {
    return amount;
}

string Incomes::getDate() {
    return date;
}

string Incomes::getItem() {
    return item;
}
