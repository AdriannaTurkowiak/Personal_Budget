#include "ExpensesFile.h"

void ExpensesFile::saveExpenseInFile(Expenses newExpense)
{
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

    return;
}
vector <Expenses> ExpensesFile::readFile(int loggedUserId)
{
    Expenses newExpense;

    CMarkup xml;
    xml.Load (EXPENSES_FILE_NAME);

    xml.FindElem("ExpenseData");
    xml.IntoElem();

    while(xml.FindElem("SingleExpense")) {
        xml.IntoElem();

        xml.FindElem("ExpenseID");
        newExpense.setExpenseId(atoi(MCD_2PCSZ(xml.GetData())));

        xml.FindElem("UserID");
        newExpense.setUserId(atoi(MCD_2PCSZ(xml.GetData())));

        xml.FindElem("IncomeDate");
        newExpense.setDate(MCD_2PCSZ(xml.GetData()));

        xml.FindElem("IncomeItem");
        newExpense.setItem(MCD_2PCSZ(xml.GetData()));

        xml.FindElem("IncomeAmount");
        newExpense.setAmount(atoi(MCD_2PCSZ(xml.GetData())));

        xml.OutOfElem();
        expenses.push_back(newExpense);
    }
    return expenses;
}

