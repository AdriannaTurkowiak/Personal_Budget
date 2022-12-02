#include "ExpensesFile.h"

void ExpensesFile::saveExpenseInFile(Expenses newExpense) {
    CMarkup xml;
    bool fileExists = xml.Load(EXPENSES_FILE_NAME);

    if (!fileExists) {
        xml.AddElem("ExpenseData");
    }

    xml.FindElem();
    xml.IntoElem();

    xml.AddElem("SingleExpense");
    xml.IntoElem();
    xml.AddElem( "ExpenseID", newExpense.getExpenseId());
    xml.AddElem( "UserID", newExpense.getUserId());
    xml.AddElem( "Date", newExpense.getDate());
    xml.AddElem( "Item", newExpense.getItem());
    xml.AddElem( "Amount", newExpense.getAmount());
    xml.OutOfElem();
    xml.Save(EXPENSES_FILE_NAME);
}

vector <Expenses> ExpensesFile::readFile(int loggedUserId) {
    Expenses newExpense;

    CMarkup xml;
    xml.Load (EXPENSES_FILE_NAME);

    xml.FindElem("ExpenseData");
    xml.IntoElem();

    while(xml.FindElem("SingleExpense")) {
        xml.IntoElem();

        xml.FindElem("ExpenseID");
        int expenseId = stoi(xml.GetData());
        newExpense.setExpenseId(expenseId);

        xml.FindElem("UserID");
        int userId = stoi(xml.GetData());
        newExpense.setUserId(userId);

        xml.FindElem("Date");
        string date = xml.GetData();
        newExpense.setDate(date);

        xml.FindElem("Item");
        string item = xml.GetData();
        newExpense.setItem(item);

        xml.FindElem("Amount");
        string amount = xml.GetData();
        newExpense.setAmount(amount);

        xml.OutOfElem();
        expenses.push_back(newExpense);
    }
    return expenses;
}
