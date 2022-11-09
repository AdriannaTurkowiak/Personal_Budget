#include "IncomeManager.h"

void IncomeManager::incomeRegister()
{
    income = getNewIncomeInfo();
    incomes.push_back(income);
    incomesFile.saveIncomeInFile(income);
}
Incomes IncomeManager::getNewIncomeInfo()
{
    Incomes newIncome;
    cout << incomes.size();
    int incomeId;
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
int IncomeManager::getNewIncomeId()
{
    if (incomes.empty() == true)
        return 1;
    else
        return incomes.back().getIncomeId() + 1;
}
