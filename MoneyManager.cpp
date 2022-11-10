#include "MoneyManager.h"

void MoneyManager::incomeRegister()
{
    income = getNewIncomeInfo();
    incomes.push_back(income);
    incomesFile.saveIncomeInFile(income);

    cout << endl << "New income is registered." << endl << endl;
    system("pause");
}
Incomes MoneyManager::getNewIncomeInfo()
{
    Incomes newIncome;

    int incomeId = 0;
    incomeId = getNewIncomeId();
    newIncome.setIncomeId(incomeId);

    newIncome.setUserId(LOGGED_USER_ID);

    unsigned int amount;
    string date, item;

    cout << "Enter date of income: ";
    cin >> date;
    newIncome.setDate(date);

    cout << "Enter item of income: " << endl;
    cin >> item;
    newIncome.setItem(item);

    cout << "Enter amount of income: " << endl;
    cin >> amount;
    newIncome.setAmount(amount);

    return newIncome;
}
int MoneyManager::getNewIncomeId()
{
    if (incomes.empty() == true)
        return 1;
    else
    {int NewIncomeId = 0;
     NewIncomeId = incomes.back().getIncomeId() + 1;
        return NewIncomeId;}
}
void MoneyManager::expenseRegister()
{
    expense = getNewExpenseInfo();
    expenses.push_back(expense);
    expenseFile.saveExpenseInFile(expense);

    cout << endl << "New expense is registered." << endl << endl;
    system("pause");
}
Expenses MoneyManager::getNewExpenseInfo()
{
    Expenses newExpense;
    cout << expenses.size();

    int expenseId = 0;
    expenseId = getNewExpenseId();
    newExpense.setExpenseId(expenseId);

    newExpense.setUserId(LOGGED_USER_ID);

    unsigned int amount;
    string date, item;

    cout << "Enter date of expense: ";
    cin >> date;
    newExpense.setDate(date);

    cout << "Enter item of expense: " << endl;
    cin >> item;
    newExpense.setItem(item);

    cout << "Enter amount of expense: " << endl;
    cin >> amount;
    newExpense.setAmount(amount);

    return newExpense;
}
int MoneyManager::getNewExpenseId()
{
    if (expenses.empty() == true)
        return 1;
    else
    {int NewExpenseId = 0;
     NewExpenseId = expenses.back().getExpenseId() + 1;
        return NewExpenseId;}
}
