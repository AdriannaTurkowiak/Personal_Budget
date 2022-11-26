#include "MoneyManager.h"

void MoneyManager::incomeRegister() {
    income = getNewIncomeInfo();
    incomes.push_back(income);
    incomesFile.saveIncomeInFile(income);

    cout << endl << "New income is registered." << endl << endl;
    system("pause");
}

Incomes MoneyManager::getNewIncomeInfo() {
    Incomes newIncome;
    char selection = {0};
    int incomeId = 0;
    incomeId = getNewIncomeId();
    newIncome.setIncomeId(incomeId);

    newIncome.setUserId(LOGGED_USER_ID);

    float amount;
    string date, item = "", amountStr;

    cout << "Is this income for today? Enter Yes 'Y' or No 'N': " << endl;
    cin >> selection;

    switch (selection) {
    case 'Y': case 'y':
        newIncome.setDate(dateManager.findToday());
        break;
    case 'N': case 'n': {
        cout << "Enter date of income in format: yyyy-mm-dd: ";
        cin >> date;
        if (isDateCorrect(date) == true)
            newIncome.setDate(date);
        break;
    }
    default: {
        cout << "This is NOT an option button. Please try again." << endl;
        cout << endl << endl;
        break;
    }
    }
    cin.ignore(std::numeric_limits <std::streamsize>::max(), '\n' );
    cout << "Enter item of income: " << endl;
    getline(cin,item);
    newIncome.setItem(item);

    cout << "Enter amount of income with two decimal place: " << endl;
    cin >> amountStr;
    amountStr = changeCommaToDot(amountStr);
    newIncome.setAmount(amountStr);

    return newIncome;
}

int MoneyManager::getNewIncomeId() {
    if (incomes.empty() == true)
        return 1;
    else {
        int NewIncomeId = 0;
        NewIncomeId = incomes.back().getIncomeId() + 1;
        return NewIncomeId;
    }
}

void MoneyManager::expenseRegister() {
    expense = getNewExpenseInfo();
    expenses.push_back(expense);
    expenseFile.saveExpenseInFile(expense);

    cout << endl << "New expense is registered." << endl << endl;
    system("pause");
}

Expenses MoneyManager::getNewExpenseInfo() {
    Expenses newExpense;

    char selection = {0};
    int expenseId = 0;
    expenseId = getNewExpenseId();
    newExpense.setExpenseId(expenseId);

    newExpense.setUserId(LOGGED_USER_ID);

    float amount;
    string date, item = "", amountStr;

    cout << "Is this income for today? Enter Yes 'Y' or No 'N': " << endl;
    cin >> selection;

    switch (selection) {
    case 'Y': case 'y':
        newExpense.setDate(dateManager.findToday());
        break;
    case 'N': case 'n': {
        cout << "Enter date of expense in format: yyyy-mm-dd: ";
        cin >> date;
        if (isDateCorrect(date) == true)
            newExpense.setDate(date);
        break;
    }
    default: {
        cout << "This is NOT an option button. Please try again." << endl;
        cout << endl << endl;
        break;
    }
    }

    cin.ignore(std::numeric_limits <std::streamsize>::max(), '\n' );
    cout << "Enter item of expense: " << endl;
    getline(cin,item);
    newExpense.setItem(item);

    cout << "Enter amount of expense with two decimal place: " << endl;
    cin >> amountStr;
    amountStr = changeCommaToDot(amountStr);
    newExpense.setAmount(amountStr);

    return newExpense;
}

int MoneyManager::getNewExpenseId() {
    if (expenses.empty() == true)
        return 1;
    else {
        int NewExpenseId = 0;
        NewExpenseId = expenses.back().getExpenseId() + 1;
        return NewExpenseId;
    }
}

bool MoneyManager::isDateCorrect(string date) {

    int year = 0, month = 0, day = 0;
    string today = dateManager.findToday();

    year = stoi(date.substr(0,4));
    month = stoi(date.substr(5,6));
    day = stoi(date.substr(8,9));

    if ((date.length() == 10) && (year >= 2000) && (year <= stoi(today.substr(0,4))) && (month >= 1) && (month <= 12) && (day >=1) && (day <= dateManager.getNumberOfDaysInMonth(month, year)))
        return true;

    else {
        cout << "This is NOT good date format. Please try again." << endl;
        cout << endl << endl;
        system("pause");
        return false;
    }
}

string MoneyManager::changeCommaToDot (string amount) {

    int foundComma = 0;
    foundComma = amount.find_last_of(",");
    //foundDot = amount.find_last_of(".");

    if (foundComma > 0)
    amount.replace(foundComma,1,".");

    return amount;
}
