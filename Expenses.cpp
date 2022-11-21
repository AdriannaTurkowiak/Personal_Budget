#include "Expenses.h"

void Expenses::setExpenseId (int newExpenseId) {
    if(newExpenseId >= 0)
        expenseId = newExpenseId;
}
void Expenses::setUserId (int newUserId) {
    if(newUserId >= 0)
        userId = newUserId;
}
void Expenses::setAmount (int newAmount) {
    amount = newAmount;
}
void Expenses::setDate (string newDate) {
    date = newDate;
}
void Expenses::setItem (string newItem) {
    item = newItem;
}
int Expenses::getExpenseId() {
    return expenseId;
}
int Expenses::getUserId() {
    return userId;
}
int Expenses::getAmount() {
    return amount;
}
string Expenses::getDate() {
    return date;
}
string Expenses::getItem() {
    return item;
}
