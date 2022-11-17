#include "PersonalBudget.h"

void PersonalBudget::userRegister()
{
    userManager.userRegister();
}
void PersonalBudget::incomeRegister()
{
    moneyManager->incomeRegister();
}
void PersonalBudget::expenseRegister()
{
    moneyManager->expenseRegister();
}
void PersonalBudget::logIn()
{
    userManager.userLogIn();
    if(userManager.isUserLogged()){
        moneyManager = new MoneyManager(INCOME_FILE_NAME,userManager.getIdOfLoggedUser(), EXPENSE_FILE_NAME);
    }
}
bool PersonalBudget::isUserLogged()
{
    return userManager.isUserLogged();
}
char PersonalBudget::userMenu()
{
  char selection;

        cout << " >>> USER MENU <<<" << endl;
        cout << "---------------------------" << endl;
        cout << "1. Add income" << endl;
        cout << "2. Add expense" << endl;
        cout << "3. Compare dates" << endl;
        cout << "4. Find today" << endl;
        cout << "5. Last month" << endl;
        cout << "6. Exit" << endl;
        cout << "---------------------------" << endl;
        cout << "Your choice: " << endl;
        cin >> selection;

  return selection;
}
void PersonalBudget::findToday()
{
        date.findToday();
}
void PersonalBudget::compareDate()
{
    return date.compareDate();
}
void PersonalBudget::getLastMonthFirstDay()
{
        date.getLastMonthFirstDay();
}
